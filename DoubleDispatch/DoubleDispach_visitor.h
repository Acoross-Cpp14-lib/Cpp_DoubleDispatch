#pragma once

#include <iostream>

//namespace acoross {
//namespace doubledispatch {

class RelationBase;
class CreatureRelation;
class UserRelation;
class NpcRelation;

// ���� �Լ� ������.
// ���� ������ ������� ������, 
// obj1, obj2 ������ �ٸ� �Լ���, IsEnemyTo(obj2, obj1) �� ȣ���Ѵ�.
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

// double dispatch �� ���� ��ɼ� Ŭ����
// ��ü�� concrete type �� ���� ����� �Ѵ�.
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
