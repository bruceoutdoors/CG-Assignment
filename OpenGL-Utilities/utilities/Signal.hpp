/********************************************
Course : TGD2151 Computer Graphics Fundamentals /
         TCS2111 Computer Graphics
Session: Trimester 2, 2015/16
ID and Name #1 : 1141125087 Hii Yong Lian
Contacts    #1 : 016-4111005 yonglian146@gmail.com
ID and Name #2 : 112272848 Lee Zhen Yong
Contacts    #2 : 016-3188854 bruceoutdoors@gmail.com
********************************************/

#pragma once

#include <functional>
#include <map>

template<class... Args>
class Signal
{
public:
    ~Signal()
    {
        disconnectAll();
    }

    // connect to slot; returns function that disconnects this link
    std::function<void()> connect(std::function<void(Args... args)> func)
    {
        int funcKey = m_key;
        m_funcs[m_key++] = func;

        return [=]() {
            m_funcs.erase(funcKey);
        };
    }

    void broadcast(Args... args)
    {
        for (auto &func : m_funcs) {
            func.second(args...);
        }
    }

    void disconnectAll()
    {
        m_funcs.clear();
    }

private:
    int m_key;
    std::map<int, std::function<void(Args...)> > m_funcs;
};
