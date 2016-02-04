#include <iostream>
#include <typeinfo>
#include <memory>
#include <vector>
#include <array>

#include <./DoubleDispatch_lookup.h>
#include <./DoubleDispach_visitor.h>

void TestDDByLookup()
{
	// 실패했다.
	// Creature* obj 의 typeid 는 Creature* 이다. User* 가 나오지 않음.

	/*using namespace acoross;
	using namespace acoross::doubledispatch;

	Creature creature;
	User user;
	Npc npc;
	Pet pet;
	Summon summon;

	Creature* obj = new User();
	IsEnemy(creature, user);
	delete obj;*/
}

void TestDDByVisitor()
{
	// 가상함수 방법
	// 잘 된다.

	using namespace std;
	//using namespace acoross::doubledispatch;

	{
		array<unique_ptr<RelationBase>, 3> arr = 
		{ 
			make_unique<CreatureRelation>(),
			make_unique<UserRelation>(),
			make_unique<NpcRelation>(),
		};
		
		for (auto& obj1 : arr)
		{
			for (auto& obj2 : arr)
			{
				obj1->IsEnemyTo(*obj2);
			}
			cout << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	TestDDByVisitor();

	return 0;
}