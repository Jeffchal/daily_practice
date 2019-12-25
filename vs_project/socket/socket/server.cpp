/*************************************************************************
	> File Name: server.cpp
	> Author: SongLee
	> E-mail: lisong.shine@qq.com
	> Created Time: 2016��04��28�� ������ 22ʱ02��43��
	> Personal Blog: http://songlee24.github.io/
	> https ://blog.csdn.net/lisonglisonglisong/article/details/51328062
 ************************************************************************/
#include<netinet/in.h>   // sockaddr_in
#include<sys/types.h>    // socket
#include<sys/socket.h>   // socket
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/select.h>   // select
#include<sys/ioctl.h>
#include<sys/time.h>
#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
#define BUFFER_SIZE 1024

struct PACKET_HEAD
{
	int length;
};

class Server
{
private:
	struct sockaddr_in server_addr;
	socklen_t server_addr_len;
	int listen_fd;    // ������fd
	int max_fd;       // ����fd
	fd_set master_set;   // ����fd���ϣ���������fd�Ϳͻ���fd   
	fd_set working_set;  // ��������
	struct timeval timeout;
public:
	Server(int port);
	~Server();
	void Bind();
	void Listen(int queue_len = 20);
	void Accept();
	void Run();
	void Recv(int nums);
};

Server::Server(int port)
{
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htons(INADDR_ANY);
	server_addr.sin_port = htons(port);
	// create socket to listen
	listen_fd = socket(PF_INET, SOCK_STREAM, 0);
	if (listen_fd < 0)
	{
		cout << "Create Socket Failed!";
		exit(1);
	}
	int opt = 1;
	setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
}

Server::~Server()
{
	for (int fd = 0; fd <= max_fd; ++fd)
	{
		if (FD_ISSET(fd, &master_set))
		{
			close(fd);
		}
	}
}

void Server::Bind()
{
	if (-1 == (bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr))))
	{
		cout << "Server Bind Failed!";
		exit(1);
	}
	cout << "Bind Successfully.\n";
}

void Server::Listen(int queue_len)
{
	if (-1 == listen(listen_fd, queue_len))
	{
		cout << "Server Listen Failed!";
		exit(1);
	}
	cout << "Listen Successfully.\n";
}

void Server::Accept()
{
	struct sockaddr_in client_addr;
	socklen_t client_addr_len = sizeof(client_addr);

	int new_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_addr_len);
	if (new_fd < 0)
	{
		cout << "Server Accept Failed!";
		exit(1);
	}

	cout << "new connection was accepted.\n";
	// ���½��������ӵ�fd����master_set
	FD_SET(new_fd, &master_set);
	if (new_fd > max_fd)
	{
		max_fd = new_fd;
	}
}

void Server::Run()
{
	max_fd = listen_fd;   // ��ʼ��max_fd
	FD_ZERO(&master_set);
	FD_SET(listen_fd, &master_set);  // ��Ӽ���fd

	while (1)
	{
		FD_ZERO(&working_set);
		memcpy(&working_set, &master_set, sizeof(master_set));

		timeout.tv_sec = 30;
		timeout.tv_usec = 0;

		int nums = select(max_fd + 1, &working_set, NULL, NULL, &timeout);
		if (nums < 0)
		{
			cout << "select() error!";
			exit(1);
		}

		if (nums == 0)
		{
			//cout << "select() is timeout!";
			continue;
		}

		if (FD_ISSET(listen_fd, &working_set))
			Accept();   // ���µĿͻ�������
		else
			Recv(nums); // ���տͻ��˵���Ϣ
	}
}

void Server::Recv(int nums)
{
	for (int fd = 0; fd <= max_fd; ++fd)
	{
		if (FD_ISSET(fd, &working_set))
		{
			bool close_conn = false;  // ��ǵ�ǰ�����Ƿ�Ͽ���

			PACKET_HEAD head;
			recv(fd, &head, sizeof(head), 0);   // �Ƚ��ܰ�ͷ���������ܳ���

			char* buffer = new char[head.length];
			bzero(buffer, head.length);
			int total = 0;
			while (total < head.length)
			{
				int len = recv(fd, buffer + total, head.length - total, 0);
				if (len < 0)
				{
					cout << "recv() error!";
					close_conn = true;
					break;
				}
				total = total + len;
			}

			if (total == head.length)  // ���յ�����Ϣԭ�����ظ��ͻ���
			{
				int ret1 = send(fd, &head, sizeof(head), 0);
				int ret2 = send(fd, buffer, head.length, 0);
				if (ret1 < 0 || ret2 < 0)
				{
					cout << "send() error!";
					close_conn = true;
				}
			}

			delete buffer;

			if (close_conn)  // ��ǰ������������⣬�ر���
			{
				close(fd);
				FD_CLR(fd, &master_set);
				if (fd == max_fd)  // ��Ҫ����max_fd;
				{
					while (FD_ISSET(max_fd, &master_set) == false)
						--max_fd;
				}
			}
		}
	}
}

int main()
{
	Server server(15000);
	server.Bind();
	server.Listen();
	server.Run();
	return 0;
}