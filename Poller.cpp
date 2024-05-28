#include "Poller.h"
#include "Channel.h"
Poller::Poller(EventLoop* loop)
    :ownerLoop_(loop){

}

bool Poller::hasChannel(Channel* channel) const {

    auto item = channels_.find(channel->fd());
    /* item 不等于 null 与 item 取出来的value == 传入的值*/
    return item != channels_.end() && item->second == channel;
}
