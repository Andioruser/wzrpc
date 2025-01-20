#ifndef RPC_MUTEX_H
#define RPC_MUTEX_H 

#include <pthread.h>
#include <memory>
#include <queue>

namespace rpc {

template<class T>
struct ScopedLockImpl {
public:
    ScopedLockImpl(T& mutex): m_mutex(mutex) {
        m_mutex.lock();
        m_locked = true;
    }
    ~ScopedLockImpl() {
        if (m_locked) {
            m_mutex.unlock();
            m_locked = false;
        }
    }
    void lock() {
        if (!m_locked) {
            m_mutex.lock();
            m_locked = true;
        }
    }
    void unlock() {
        if (m_locked) {
            m_mutex.unlock();
            m_locked = false;
        }
    }
private:
    T &m_mutex;
    bool m_locked;
};

template <class T>
struct ReadScopedLockImpl
{
public:
  ReadScopedLockImpl(T &mutex)
      : m_mutex(mutex)
  {
    m_mutex.rdlock();
    m_locked = true;
  }

  ~ReadScopedLockImpl()
  {
    unlock();
  }

  void lock()
  {
    if (!m_locked)
    {
      m_mutex.rdlock();
      m_locked = true;
    }
  }

  void unlock()
  {
    if (m_locked)
    {
      m_mutex.unlock();
      m_locked = false;
    }
  }

private:
  /// mutex
  T &m_mutex;
  /// 是否已上锁
  bool m_locked;
};

/**
 * @brief 局部写锁模板实现
 */
template <class T>
struct WriteScopedLockImpl
{
public:
  WriteScopedLockImpl(T &mutex)
      : m_mutex(mutex)
  {
    m_mutex.wrlock();
    m_locked = true;
  }

  ~WriteScopedLockImpl()
  {
    unlock();
  }

  void lock()
  {
    if (!m_locked)
    {
      m_mutex.wrlock();
      m_locked = true;
    }
  }

  void unlock()
  {
    if (m_locked)
    {
      m_mutex.unlock();
      m_locked = false;
    }
  }

private:
  T &m_mutex;
  bool m_locked;
};
}


#endif