#ifndef DOUBLEDISPATCH_DOUBLEDISPATCH_H_
#define DOUBLEDISPATCH_DOUBLEDISPATCH_H_

// 아래 코드는 제대로 돌아가지 않는 코드이다.

//#include <iostream>
//#include <map>
//#include <string>
//#include <memory>
//#include <typeinfo>
//
//namespace acoross {
//
//class Creature
//{
//public:
//	virtual void Foo() const
//	{
//		std::cout << "Creature" << std::endl;
//	}
//};
//class User : public Creature
//{
//public:
//	virtual void Foo() const override
//	{
//		std::cout << "User" << std::endl;
//	}
//};
//class Npc : public Creature
//{};
//class Pet : public Npc
//{};
//class Summon : public Npc
//{};
//
//namespace doubledispatch {
//
//static bool IsEnemyCreatureCreature(Creature& obj1, Creature& obj2)
//{
//	std::cout << __FUNCSIG__ << std::endl;
//	return false;
//}
//static bool IsEnemyCreatureUser(Creature& obj1, Creature& obj2)
//{
//	std::cout << __FUNCSIG__ << std::endl;
//	return false;
//}
//static bool IsEnemyCreatureNpc(Creature& obj1, Creature& obj2)
//{
//	std::cout << __FUNCSIG__ << std::endl;
//	return false;
//}
//static bool IsEnemyCreaturePet(Creature& obj1, Creature& obj2)
//{
//	std::cout << __FUNCSIG__ << std::endl;
//	return false;
//}
//static bool IsEnemyCreatureSummon(Creature& obj1, Creature& obj2)
//{
//	std::cout << __FUNCSIG__ << std::endl;
//	return false;
//}
//
//typedef bool(*EnemyCheckFunc)(Creature&, Creature&);
//typedef std::map<std::pair<std::string, std::string>, EnemyCheckFunc> EnemyCheckFuncMap;
//
//template<typename T1, typename T2>
//void SetFunc(EnemyCheckFuncMap& map, EnemyCheckFunc func)
//{
//	using namespace std;
//	auto t1 = typeid(T1).name();
//	auto t2 = typeid(T2).name();
//	map[make_pair(t1, t2)] = func;
//}
//
//EnemyCheckFuncMap initEnemyCheckMap()
//{
//	using namespace std;
//
//	EnemyCheckFuncMap map;
//	SetFunc<Creature, Creature>(map, &IsEnemyCreatureCreature);
//	SetFunc<Creature, User>(map, &IsEnemyCreatureUser);
//	SetFunc<Creature, Npc>(map, &IsEnemyCreatureNpc);
//	SetFunc<Creature, Pet>(map, &IsEnemyCreaturePet);
//	SetFunc<Creature, Summon>(map, &IsEnemyCreatureSummon);
//
//	return map;
//}
//
//EnemyCheckFunc lookup(const std::string& class1, const std::string& class2)
//{
//	using namespace std;
//	static auto map = initEnemyCheckMap();
//
//	auto mapEntry = map.find(make_pair(class1, class2));
//
//	if (mapEntry == map.end())
//		return nullptr;
//	return mapEntry->second;
//}
//
//bool IsEnemy(Creature& obj1, Creature& obj2)
//{
//	auto func = lookup(typeid(obj1).name(),
//		typeid(obj2).name());
//	
//	if (func)
//	{
//		return func(obj1, obj2);
//	}	
//	else
//	{
//		throw new std::exception("unknown enemy check");
//	}
//
//	return false;
//}
//
//}//namespace doubledispatch 
//}//namespace acoross 
#endif //DOUBLEDISPATCH_DOUBLEDISPATCH_H_