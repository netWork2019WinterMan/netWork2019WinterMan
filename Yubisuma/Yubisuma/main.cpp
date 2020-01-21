#include "Sock.h"
#include <thread>

Sock* sock;

//クラスの生成
void Create(void)
{
	sock = new Sock();
}

//接続
void Accept(void)
{
	while (true)
	{
		sock->Accept();
	}
}

//受信
void Recv(void)
{
	while (true)
	{
		sock->Recv();
	}
}

//送信
void Send(void)
{
	while (true)
	{
		sock->Send();
	}
}
//エントリーポイント
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