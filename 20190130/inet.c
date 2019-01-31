#include <func.h>

int main()
{
	char ip[]="192.168.0.101";

	struct in_addr myaddr;
	//inet_aton
	int iRet=inet_aton(ip,&myaddr);//将十进制的IP地址转换为网络字节序的32位的二进制数值
	printf ("%x\n",myaddr.s_addr);

	//inet_addr
	printf ("%x\n",inet_addr(ip));//功能与inet_aton相同

	//inet_pton
	iRet=inet_pton(AF_INET,ip,&myaddr);//功能与inet_aton相同，AFINET表示IPv4
	printf ("%x\n",myaddr.s_addr);


	myaddr.s_addr=0xac100ac4;
	//inet_ntoa
    printf ("%s\n",inet_ntoa(myaddr));//将网络字节序的32位二进制数值转换为十进制的IP地址


	//inet_ntop
	inet_ntop(AF_INET,&myaddr,ip,16);
	puts(ip);
	return 0;
}



