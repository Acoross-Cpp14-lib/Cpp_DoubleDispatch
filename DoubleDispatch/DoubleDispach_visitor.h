#pragma once

#include <iostream>

//namespace acoross {
//namespace doubledispatch {

class RelationBase;
class CreatureRelation;
class UserRelation;
class NpcRelation;

// 실제 함수 구현부.
// 인자 순서는 상관없기 때문에, 
// obj1, obj2 순서만 다른 함수는, IsEnemyTo(obj2, obj1) 을 호출한다.
class EnemyChecker
{
public:
	static bool IsEnemyTo(CreatureRelation& obj1, CreatureRelation& obj2)
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	static bool IsEnemyTo(CreatureRelation& obj1, UserRelation& obj2)
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	static bool IsEnemyTo(CreatureRelation& obj1, NpcRelation& obj2)
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}

	static bool IsEnemyTo(UserRelation& obj1, CreatureRelation& obj2)
	{
		return IsEnemyTo(obj2, obj1);
	}
	static bool IsEnemyTo(UserRelation& obj1, UserRelation& obj2)
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	static bool IsEnemyTo(UserRelation& obj1, NpcRelation& obj2)
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}

	static bool IsEnemyTo(NpcRelation& obj1, CreatureRelation& obj2)
	{
		return IsEnemyTo(obj2, obj1);
	}
	static bool IsEnemyTo(NpcRelation& obj1, UserRelation& obj2)
	{
		return IsEnemyTo(obj2, obj1);
	}
	static bool IsEnemyTo(NpcRelation& obj1, NpcRelation& obj2)
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
};

// double dispatch 를 위한 기능성 클래스
// 객체의 concrete type 을 얻어내는 기능을 한다.
class RelationBase
{
public:
	virtual bool IsEnemyTo(RelationBase& other) = 0;
	virtual bool IsEnemyTo(CreatureRelation& other) = 0;
	virtual bool IsEnemyTo(UserRelation& other) = 0;
	virtual bool IsEnemyTo(NpcRelation& other) = 0;
};

#define RELATION_IMPL(Name)	\
class Name : public RelationBase	\
{	\
public:	\
	virtual bool IsEnemyTo(RelationBase& other) override	\
	{	\
		return other.IsEnemyTo(*this);	\
	}	\
	virtual bool IsEnemyTo(CreatureRelation& other) override	\
	{	\
		/*std::cout << __FUNCSIG__ << std::endl;*/	\
		return EnemyChecker::IsEnemyTo(other, *this);	\
	}	\
	virtual bool IsEnemyTo(UserRelation& other) override	\
	{	\
		/*std::cout << __FUNCSIG__ << std::endl;*/	\
		return EnemyChecker::IsEnemyTo(other, *this);	\
	}	\
	virtual bool IsEnemyTo(NpcRelation& other) override	\
	{	\
		/*std::cout << __FUNCSIG__ << std::endl;*/	\
		return EnemyChecker::IsEnemyTo(other, *this);	\
	}	\
};

RELATION_IMPL(CreatureRelation);
RELATION_IMPL(UserRelation);
RELATION_IMPL(NpcRelation);

//}
//}
