#include <thread>
#include <mutex>
#include "NonCopyable.hpp"

template <typename T>
class Singleton : NonCopyable
{
public:
    template<typename... Args>
	static T* Instance(Args&&... args) {
        if(m_pInstance==nullptr) {
			std::call_once(flag, [&]() { m_pInstance = new T(std::forward<Args>(args)...); });
		}
        return m_pInstance;
    }
	
	static T* GetInstance() {
		if (m_pInstance == nullptr)
			throw std::logic_error("the instance is not init, please initialize the instance first");
		return m_pInstance;
	}

    static void DestroyInstance()
    {
        delete m_pInstance;
        m_pInstance = nullptr;
    }

private:
        Singleton(void);
        virtual ~Singleton(void);
private:
    static std::once_flag flag;
    static T* m_pInstance;
};

template <typename T> 
std::once_flag Singleton<T>::flag;

template <typename T> 
T* Singleton<T>::m_pInstance = nullptr;
