/** 
2 * 
3 *  File Name: Common.hpp 
4 *  brief: 
5 *  Create Time: 2015年10月13日 17:47 
6 *  Author Gavin 
7 */  
#ifndef COMMON_H
#define COMMON_H
namespace Comon
{
ifdef WIN_32
typedef SOCKET GAVIN_SOCKET
#else
  typedef int GAVIN_SOCKET
#endif
  inline bool SetNoDelay(GAVIN_SOCKET fd)
  {
#ifndef WIN_32
    int isTrue = true?1:0;
    //                  IPPROTO_TCP表示在那个层
    //level：选项定义的层次；支持SOL_SOCKET、IPPROTO_TCP、IPPROTO_IP和IPPROTO_IPV6。
    //获取或者设置与某个套接字关联的选项
    return setsockopt(fd,IPPROTO_TCP,TCP_NODELAY,(char*)&isTrue,sizeof(isTrue)) == 0;//TCP_NODELAY BOOL 禁止发送合并的Nagle算法。
#endif
  }
  inline bool SetNonBlocking(GAVIN_SOCKET fd)
  {
#ifndef WIN_32
    return fcntl((fd),F_SETFL,fcntl((fd),F_GETFL) | O_NONBLOCK) == 0;
#endif
  }
  struct Requesthandle
  {
    epoll_event _event;
    char        _type;
    char        _linkstat;
    int         _fd;
    void*       _ptr;
    enum REG_TYPE
    {
      REG_POLLER,
      REG_TCP_SOCKET,
      REG_TCP_ACCEPT,
      REG_DUP_SOCKET
    };
    REquestHandle()
    {
      memset(this,0,sizeof(*this));
    }
  };
}
#endif
