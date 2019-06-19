
#include<string>
#include<unordered_map>
#include<memory>
#include<functional>
#include "Any.hpp"
#include "NonCopyable.hpp"

using namespace std;

class IocContainer : NonCopyable
{
public:
	IocContainer(void){}
	~IocContainer(void){}

	template<class T>
	void RegisterType(const string& strKey)
	{
		std::function<T* ()> function = []{ return new T(); };
		RegisterType(strKey, function);
	}
	
	template<class T, class Depend>
	void RegisterType(const string& strKey)
	{
		std::function<T* ()> function = []{ return new T( new Depend()); };
		RegisterType(strKey, function);
	}

    template<class T>
	T* Resolve(const string& strKey)
	{
		if (m_creatorMap.find(strKey) == m_creatorMap.end())
			return nullptr;


        Any resolver = m_creatorMap[strKey];
		std::function<T* ()> function = resolver.AnyCast<std::function<T* ()>>();
		return function();
	}
	
	template<class T>
	std::shared_ptr<T> ResolveShared(const string& strKey)
	{
		T* t = Resolve<T>(strKey);
		return std::shared_ptr<T>(t);
	}

private:
	void RegisterType(const string& strKey, Any constructor)
	{
		if (m_creatorMap.find(strKey) != m_creatorMap.end())
			throw std::invalid_argument("this key has already exist!");

		m_creatorMap.emplace(strKey, constructor);
	}

private:
	unordered_map<string, Any> m_creatorMap;
};
