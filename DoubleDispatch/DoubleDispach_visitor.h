#pragma once

#include <iostream>

//namespace acoross {
//namespace doubledispatch {

class RelationBase;
class CreatureRelation;
class UserRelation;
class NpcRelation;
class PetRelation;
class SummonRelation;

class RelationBase
{
public:
	virtual bool IsEnemyTo(RelationBase& other) = 0;
	virtual bool IsEnemyTo(CreatureRelation& other) = 0;
	virtual bool IsEnemyTo(UserRelation& other) = 0;
	virtual bool IsEnemyTo(NpcRelation& other) = 0;
	virtual bool IsEnemyTo(PetRelation& other) = 0;
	virtual bool IsEnemyTo(SummonRelation& other) = 0;
};

class CreatureRelation : public RelationBase
{
public:
	virtual bool IsEnemyTo(RelationBase& other) override
	{
		return other.IsEnemyTo(*this);
	}
	
	virtual bool IsEnemyTo(CreatureRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(UserRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(NpcRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(PetRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(SummonRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
};

class UserRelation : public RelationBase
{
public:
	virtual bool IsEnemyTo(RelationBase& other) override
	{
		return other.IsEnemyTo(*this);
	}

	virtual bool IsEnemyTo(CreatureRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(UserRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(NpcRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(PetRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(SummonRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
};

class NpcRelation : public RelationBase
{
public:
	virtual bool IsEnemyTo(RelationBase& other) override
	{
		return other.IsEnemyTo(*this);
	}

	virtual bool IsEnemyTo(CreatureRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(UserRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(NpcRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(PetRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(SummonRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
};

class PetRelation : public RelationBase
{
public:
	virtual bool IsEnemyTo(RelationBase& other) override
	{
		return other.IsEnemyTo(*this);
	}

	virtual bool IsEnemyTo(CreatureRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(UserRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(NpcRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(PetRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(SummonRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
};

class SummonRelation : public RelationBase
{
public:
	virtual bool IsEnemyTo(RelationBase& other) override
	{
		return other.IsEnemyTo(*this);
	}

	virtual bool IsEnemyTo(CreatureRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(UserRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(NpcRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(PetRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
	virtual bool IsEnemyTo(SummonRelation& other) override
	{
		std::cout << __FUNCSIG__ << std::endl;
		return false;
	}
};

//}
//}
