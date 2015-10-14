/**
2  *
3  *  File Name: EpollerImpl.hpp
4  *  brief:
5  *  Create Time: 2015年10月12日 23:40:05
6  *  Author Gavin
7  */                                                                                                   
#ifndef EPOLLERIMPL_H
#define EPOLLERIMPL_H
#include <vector>
#include "Common.hpp "
#define MAX_EVENTS_SIZE 512
class EpollerImpl
{
  public:
    EpollerImpl();
    ~EpollerImpl();
    typedef std::vector<void*> vecMessage;
    bool initialize();
    void RunOnce();
    void SetEventSize(int size);
    template <typename Handle>
    inline void Post(Handle &H)
    {
      PostMessage(H);      
    }
    /*
    *brief
    *获取epoll_create()创建的文件句柄
    */
    inline int GetEpollFd() const
    {
      return m_fd;
    }
    /*
    *brief
    *判断epoll是否初始化
    */
    inline bool IsInIt() const
    {
      return m_IsInitFlags;
    }
    /*
    *brief
    *发送网络消息
    */
    void PostMessage(const std::function<void ()> &handle);
    //网络消息
    std::vector<epoll_event> m_events;
  private:
    int m_fd;
    vecMessage m_msg;
    bool m_IsInitFlags;
    int  m_sockpair[2];//建立双工通信
    std::mutex m_mutex;
    REquestHandle m_epollData;
    std::mutex      m_msglock;
}
#endif
