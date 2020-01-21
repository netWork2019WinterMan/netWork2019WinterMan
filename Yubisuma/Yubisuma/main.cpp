#include "Sock.h"
#include <thread>

Sock* sock;

//�N���X�̐���
void Create(void)
{
	sock = new Sock();
}

//�ڑ�
void Accept(void)
{
	while (true)
	{
		sock->Accept();
	}
}

//��M
void Recv(void)
{
	while (true)
	{
		sock->Recv();
	}
}

//���M
void Send(void)
{
	while (true)
	{
		sock->Send();
	}
}
//�G���g���[�|�C���g
int main()
{
	Create();

	std::thread accept(Accept);
	std::thread recv(Recv);
	std::thread send(Send);

	accept.detach();
	recv.join();
	send.detach();

	return 0;
}