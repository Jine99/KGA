//1.(부모)유닛클래스를 만듬(체력,공격력...)
//2.2개이상의 자식클래스를 만듬
//3.ex)플레이어 , 몬스터
//플레이어와 몬스터의 턴제 게임을 만들기
//ㄴget/set 이용하기
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
class Monster;



class Monster
{
public:
	Monster(string name,int maxhp,int hp, int avoid,int def, int atk, int spd,int xp,int goldreward)
		:Name(name),Maxhp(maxhp),Hp(hp),Avoid(avoid),Def(def),Atk(atk),Spd(spd),Xp(xp),GoldReward(goldreward){}
	
	
	void DefenseBreak(int dmg) 
	{
		cout << Name << "이(가)"<<dmg<<"의 방어무시 피해를 받았습니다." << endl;
		Hp -= dmg;
	} 



	void takeDmg(int dmg)
	{
		srand(time(0));
		int a = rand() % 100;
		
		if (a<=Avoid)
		{
			cout << Name << "이(가) 공격을 회피하였습니다." << endl;
		}
		else if (dmg <= Def)
		{
			cout << "공격력이 너무낮아" << Name << "의 방어력을 뚫지 못하였습니다." << endl;
			Hp -= 1;
		}
		else
		{
			cout << Name << "이(가) " << (dmg - Def) / 2 << "의 데미지를 입었습니다."<<endl;
			Hp -= (dmg - Def) / 2;
		}
	}

	string getName() {return Name;}
	int getMaxhp() { return Maxhp; }
	int getXp() {return Xp;}
	int getSpd(){return Spd;}
	int getAVoid() { return Avoid; }
	int getDef() { return Def; }
	int getGold() {return GoldReward;}
	int getHp() {return Hp;}
	int getAtk() { return Atk; }

protected:

	string Name;
	int Maxhp;
	int Hp;
	int Avoid;
	int Def;
	int Atk;
	int Spd;
	int Xp;
	int GoldReward;
private:
};
class Skill
{
public:
	Skill() : Skillname("Unnamed"), Skillinpo("No info"), Costmana(0) {}
	Skill(string skillname, string skillinpo, int costmana, int dmg, int level, bool buff = false, bool defenseBreak = false,
		bool buffDef = false, bool buffSpd = false, bool rehp = false, bool remana = false, int critChance = 0, int bufftime =0)
		:Skillname(skillname), Skillinpo(skillinpo), Costmana(costmana), Dmg(dmg), Level(level), Buff(buff), DefenseBreak(defenseBreak),
		BuffDef(buffDef), BuffSpd(buffSpd), ReHp(rehp), ReMana(remana),CritChance(critChance),Bufftime(bufftime) {}

	string getSkillname() { return Skillname; }
	string getSkillinpo() { return Skillinpo; }
	int getcostmana() { return Costmana; }
	int getLevel() { return Level; }
	int getcritChance() {return Costmana;}
	void skillcritChance() {
		CritChance += 50;
	}

	void useskill(Monster& monster, Skill& skill)
	{
		srand(time(0));
		int a = rand() % 100;
		system("cls");
		cout << "스킬 " << skill.getSkillname() << "을(를) 사용하였습니다 \n";
		if (a<=skill.CritChance)
		{	
			cout << "스킬에 치명타가 적용됩니다." << endl;
			monster.takeDmg(skill.getDmg()*2);
		}
		else
		{
			monster.takeDmg(skill.getDmg());
		}	
	}
	int getCostmana() { return Costmana; }
	bool getBuff() { return Buff; }
	bool getRehp() { return ReHp; }
	bool getRemana() { return ReMana; }
	bool getDefenseBreak(){ return DefenseBreak; }
	int getDmg() { return Dmg; }




private:
	string Skillname;
	string Skillinpo;
	int Costmana;
	int Dmg;
	int Level;
	int Bufftime;
	int CritChance;
	bool Buff;
	bool DefenseBreak;
	bool BuffDef;
	bool BuffSpd;
	bool ReHp;
	bool ReMana;


};
class Player
{
public:
	Player(string name, int level, int maxhp, int hp, int maxmana, int mana, int atk, int def, int avoid, int critdmg, int critchance, int spd, int maxexp, int exp, int gold)
		:Name(name), Level(level), Maxhp(maxhp), Hp(hp), Maxmana(maxmana), Mana(mana), Atk(atk), Def(def), Avoid(avoid), CritDmg(critdmg), CritChance(critchance), Spd(spd), Maxexp(maxexp), Exp(exp), Gold(gold) {}

	virtual void setupSkills() = 0;



	int getHp() { return Hp; }
	int gettraining() { return trainingpoint; }
	int getlevel() { return Level; }
	int getmana() { return Mana; }
	int getAtk() { return Atk; }
	int getcitcal() { return CritDmg; }
	int getGlod() { return Gold; }
	string getName() { return Name; }

	


	void training() { trainingpoint -= 1; }
	void skillcir() {
		for (int i = 0; i < 5; i++)
		{
			skills[i].skillcritChance();
		}
	}

	void setgold(int a) { Gold -= a; }
	void setmaxhp(int a) { Maxhp += a; }
	void setmaxmana(int a) { Maxmana += a; }
	void setatk(int a) { Atk += a; }
	void settraining() { trainingpoint = 3; }
	void relax() { Hp = Maxhp; Mana = Maxmana; }
	void setMana(int a) { Mana -= a; }
	void sethppotion() { Hppotion += 1; }
	void setmppotion() { mppotion += 1; }
	void setatkpotion() { atkpotion += 1; }

	void setAvoid(int a) { Avoid += a; }
	void setcritdmg(int a) { CritDmg += a; }
	void setCritChance(int a) { CritChance +=a; }
	void setDef(int a) { Def += a; }
	void setSpd(int a) { Spd += a; }

	void MakeSkill(int index, Skill skill)
	{
		skills[index] = skill;
	}
	
	void showskill(Monster& monster) 
	{	
		int select;
		do
		{
			battlestatus(monster);
			cout << "사용할 스킬을 선택하세요\n\n";
			for (int i = 0; i < 4; i++)
			{
				cout << i + 1<<"번스킬 ( " << skills[i].getSkillname() << " )\n스킬 설명 : " << skills[i].getSkillinpo() 
					<<"\n제한 레벨 : "<<skills[i].getLevel()<<"레벨" << "\n소모 마나 : " << skills[i].getCostmana() <<"\n"<< endl;
			}
			cin >> select;
			system("cls");
		} while (4 < select || 0 == select);
		if (checkMana(skills[select - 1].getCostmana()) && checkLevel(skills[select - 1].getLevel()))
		{
			Mana -= skills[select - 1].getCostmana();
			if (skills[select - 1].getBuff() == true)
			{
				if (skills[select - 1].getRehp() == true)
				{
					heal(skills[select - 1].getDmg()*Atk);
				}
				else if (skills[select - 1].getRemana() == true)
				{
					ManaRegen(skills[select - 1].getDmg()*Atk);
				}
			}
			else if (skills[select - 1].getDefenseBreak() == true)
			{

				monster.DefenseBreak(skills[select-1].getDmg()*Atk);
			}
			else
			{
				srand(time(0));
				int a = rand() % 100;
				system("cls");
				cout << "스킬 " << skills[select-1].getSkillname() << "을(를) 사용하였습니다 \n";
				if (a <= skills[select-1].getcritChance())
				{
					cout << "스킬에 치명타가 적용됩니다." << endl;
					monster.takeDmg((skills[select - 1].getDmg()*Atk) * 2);
				}
				else
				{
					monster.takeDmg(skills[select - 1].getDmg()*Atk);
				}
			}
		}
		else
		{

		}


		
	}

	 void heal(int a)
	 {
		 if (Maxhp>Hp+a)
		 {
			 Hp += a;
			 cout << Name << "의 체력이 " << a << " 만큼 회복되었습니다." << endl;
		 }
		 else
		 {
			 Hp = Maxhp;
			 cout << Name << "의 체력이 " << a << " 만큼 회복되었습니다." << endl;
		 }
	 }
	 void ManaRegen(int a) 
	 {
		 if (Maxmana > Mana + a)
		 {
			 Mana += a;
			 cout << Name << "의 마나가 " << a << " 만큼 회복되었습니다." << endl;
		 }
		 else
		 {
			 Mana = Maxmana;
			 cout << Name << "의 마나가 " << a << " 만큼 회복되었습니다." << endl;
		 }

	 }




	void status() 
	{
		cout << "=======================================================================\n";
		cout <<" " << Level << "레벨    " << Name << "\n";
		cout << "체력 : " << Maxhp << " / " << Hp << "\n";
		cout << "마나 : " << Maxmana << " / " << Mana << "\n";
		cout << "공격력: " << Atk <<  " 방어력: " << Def<<"\n";
		cout << "속도 : " << Spd << " 치명타 배율: " << CritDmg<<"배\n";
		cout << "치명타 확률: " << CritChance << "% 회피: " << Avoid << "%\n";
		cout << "경험치: " << Maxexp << " / " << Exp << "\n\n";
		cout << "소지금: " << Gold << "원 남은 훈련 : " << trainingpoint << "회\n";
		cout << "=======================================================================\n";
	}
	void battlestatus(Monster& monster) 
	{
		cout << "=======================================================================\n";
		cout << " " << Level << "레벨    " << Name << "					" << monster.getName() << "\n";
		cout << "체력 : " << Maxhp << " / " << Hp << "			체력 : " << monster.getMaxhp() << " / " << monster.getHp() << "\n";
		cout << "마나 : " << Maxmana << " / " << Mana << "			공격력: " << monster.getAtk() << " 방어력: " << monster.getDef() << "\n";
		cout << "공격력: " << Atk << " 방어력: " << Def << "			속도 : " << monster.getSpd() << " 회피" << monster.getAVoid() << "%\n";
		cout << "속도 : " << Spd << " 치명타 배율: " << CritDmg << "배\n";
		cout << "치명타 확률: " << CritChance << "% 회피: " << Avoid << "%\n";
		cout << "=======================================================================\n";

	}
	bool checkLevel(int level) 
	{
		if (Level>=level)
		{
			return true;
		}
		else 
		{
			cout << "스킬을 사용하기 위한 레벨이 부족합니다\n 내레벨 :" << Level << endl;
			return false;
		}

	}
	

	void showmyitem()
	{
		int select = 0;
		
		do
		{
			cout<< "1번  HP포션\n체력을 절반만큼 회복시켜줍니다.\n남은 갯수 : "<<Hppotion<<"개\n";
			cout << "2번  MP포션\n마나를 절반만큼 회복시켜줍니다.\n남은 갯수 : " << mppotion << "개\n";
			cout << "3번  힘의물약\n1턴간 공격력을 100만큼 올려줍니다.\n남은 갯수 : " << atkpotion << "개\n";

			cin >> select;

			switch (select)
			{
			case 1:
				if (Hppotion > 0)
				{
					cout << "체력이 절반만큼 회복됩니다." << endl;
					if (Maxhp/2<Hp)
					{
						Hp = Maxhp;
						break;
					}
					else
					{
						Hp += Maxhp / 2;
						break;
					}

				}
				else
				{
					cout << "갯수가 부족합니다."<<endl;
					break;
				}
			case 2:
				if (mppotion > 0)
				{
					cout << "마나가 절반만큼 회복됩니다." << endl;
					if (Maxmana / 2 < Mana)
					{
						Mana = Maxmana;
						break;
					}
					else
					{
						Mana += Maxmana / 2;
						break;
					}

				}
				else
				{
					cout << "갯수가 부족합니다." << endl;
					break;
				}
			case 3:
				if (atkpotion > 0)
				{
					cout << "갯수가 부족합니다." << endl;
					break;
				}
				else
				{
					cout << "갯수가 부족합니다." << endl;
					break;
				}
			default:
				system("cls");
				cout << "잘못된 입력입니다.\n" << endl;
			};

		} while (4 < select || 0 == select);





	}

	bool checkMana(int cost) 
	{
		if (Mana>=cost)
		{
			return  true;
		}
		else
		{
			cout << "마나가 부족합니다 현재 마나 :" << Mana << endl;
			return false;
		}

	}

	void PlayerAttack(Monster& monster)
	{
		srand(time(0));
		int critical = rand() % 100;

		if (critical < CritChance)
		{
			cout << "크리티컬 적중!  " << CritDmg << "배의 데미지가 들어갑니다." << endl;
			monster.takeDmg(Atk*CritDmg);
		}
		else 
		{
			monster.takeDmg(Atk);
		}
	}
	void PlayertakeDmg(int dmg) 
	{
		srand(time(0));
		int a = rand() % 101;
		int select = 0;
		do
		{
			cout << "\n1.방어한다  (내 방어력 : " << Def << ")\n2.회피한다  (내 회피확률 : " << Avoid << "%)" << endl;
			cin >> select;
			switch (select)
			{
			case 1:
				if (dmg <= Def)
				{
					system("cls");
					cout << "가드에 성공하였습니다." << 1 << "의 데미지를 받습니다.\n";
					Hp -= 1;
				}
				else
				{
					system("cls");
					cout << "방어에 성공하여" << (dmg - Def) / 2 << "의 데미지를 받습니다.\n";
					Hp -= (dmg - Def) / 2;
				}
				break;
			case 2:
				if (a <= Avoid)
				{
					system("cls");
					cout << "회피에 성공하였습니다." << endl;
				}
				else
				{
					system("cls");
					cout << "회피에 실패하였습니다." << endl;
					cout << dmg << "의 데미지를 받습니다." << endl;
					Hp -= dmg;
				}
				break;
			default:
				system("cls");
				cout << "잘못된 입력입니다.\n" << endl;

			}

		} while (2 < select || 0 == select);
	}
	void MonsterAttack(Monster& monster)
	{
		cout << monster.getName() << "이(가) 공격 을 시도합니다." << endl;
		this->PlayertakeDmg(monster.getAtk());
	}
	void battle(Monster& monster) 
	{
		system("cls");
		int playerspd = 0;
		int monsterspd = 0;
		int select = 0;
		while (Hp > 0 && monster.getHp()>0)
		{
			while (playerspd<=1000&&monsterspd<=1000)
			{
				playerspd += (100 + Spd);
				monsterspd += (100 + monster.getSpd());
			}
			battlestatus(monster);
			if (playerspd>=1000)
			{
				do
				{
					cout << "내턴 입니다 한가지 행동을 선택할수 있습니다." << endl;
					cout << "1. 공격 2.아이템 사용" << endl;
					cin >> select;
					system("cls");
					switch (select)
					{
					case 1:
						do
						{
							battlestatus(monster);
							cout << "1. 일반공격 2. 스킬창열기" << endl;
							cin >> select;
							switch (select)
							{
							case 1:
								system("cls");
								PlayerAttack(monster);
								playerspd -= 1000;
								break;
							case 2:
								system("cls");
								showskill(monster);
								playerspd -= 1000;
								break;
							default:
								system("cls");
								cout << "잘못된 입력입니다.\n" << endl;
							}
						} while (2 < select || 0 == select);
						break;
					case 2:
						system("cls");
						showmyitem();
						playerspd -= 500;
						break;
					default:
						system("cls");
						cout << "잘못된 입력입니다.\n" << endl;

					}

				} while (2 < select || 0 == select);

			}
			if (monsterspd>=1000)
			{
				MonsterAttack(monster);
				monsterspd -= 1000;
			}
	


		}
		if (Hp<=0)
		{
			cout << "당신은"<<monster.getName()<<"에게 죽었습니다 마을에서 리스폰합니다." << endl;
			Hp = Maxhp/2;	delete& monster;
		}
		else if (monster.getHp()<=0)
		{
			cout << monster.getName() << "이(가) 쓰려졌습니다." << endl;
			cout << monster.getGold() << " 골드와" << monster.getXp() << " 의 경험치를 얻습니다." << endl;
			win(monster);			delete& monster;
		}

	}
	void win(Monster& monster) 
	{
		Gold += monster.getGold();
		Levelup(monster);
		settraining();

	}
	void Levelup(Monster& monster) 
	{
		Exp += monster.getXp();
		while (Maxexp <= Exp)
		{
			int select = 0;
			Levelpoint += 3; Level += 1;
			Exp -= Maxexp; Maxexp += 100;
			cout << "축하합니다 레벨업을 하였습니다." << endl;
			cout << " 포인트 3개를 얻습니다.  능력치를 선택하여 찍을수 있습니다.\n" << endl;
			while (Levelpoint > 0)
			{
				do
				{
					status();
					cout << "1.최대체력 50 증가  2.최대마나 30 증가   3.공격력 5 증가 \n" << endl;
					cout << "남은 포인트 : " << Levelpoint << "\n" << endl;
					cin >> select;

					switch (select)
					{
					case 1:
						system("cls");
						cout << "최대체력이 50 증가합니다.\n";
						Maxhp += 50;  Levelpoint -= 1;
						break;
					case 2:
						system("cls");
						cout << "최대마나가 30 증가합니다.\n";
						Maxmana += 30;  Levelpoint -= 1;
						break;
					case 3:
						system("cls");
						cout << "공격력이 5 증가합니다.\n";
						Atk += 5;	Levelpoint -= 1;
						break;
					default:
						system("cls");
						cout << "잘못된 입력입니다.\n" << endl;
					}
				} while (3 < select || 0 == select);

				

			}
		}


	}



protected:
	string Name;
	int Level;
	int Levelpoint = 0;
	int Maxhp;
	int Hp;
	int Maxmana;
	int Mana;
	int Atk;
	int Def;
	int	Avoid;
	int CritDmg;
	int CritChance;
	int Spd;
	int Maxexp;
	int Exp;
	int Gold;
	int trainingpoint = 3;
	int Hppotion = 0;
	int mppotion = 0;
	int atkpotion = 0;
	Skill skills[4];


private:

};
class Shop
{
public:
	Shop() : Name(""), Inpo(""), Price(0), Number(0), Soldout(true) {}
	Shop(string name,string inpo ,int price, int number, bool soldout=true) :Name(name),Inpo(inpo), Price(price), Number(number), Soldout(soldout) {}

	string getName() { return Name; }
	string getInpo() { return Inpo; }
	int getPrice() { return Price; }
	int getNumber() { return Number; }
	bool getSoldout() { return Soldout; }

	void setNumber(int a) { Number -= a; };




protected:
	string Name;
	string Inpo;
	int Price;
	int Number;
	bool Soldout;

};
class Item
{

public:
	Item() { shopset(); }
	void makeietm(int index, Shop Item)
	{
		item[index] = Item;
	}
	void shopset()
	{
		makeietm(0, Shop("HP포션", "체력을 절반만큼 회복시켜줍니다.", 50, 1000));
		makeietm(1, Shop("MP포션", "마나를 절반만큼 회복시켜줍니다", 50, 1000));
		makeietm(2, Shop("힘의 물약", "공격력이 1턴간 100 증가합니다.", 100, 1000));
		makeietm(3, Shop("초보자 장비", "체력:50 방어력:5를 올려줍니다.", 0, 1));
		makeietm(4, Shop("회피 망토", "회피확률이 5프로 증가합니다.", 250, 1));
		makeietm(5, Shop("마력의 돌", "최대 마나가 200 증가합니다.", 500, 20));
		makeietm(6, Shop("체력의 돌", "최대 체력이 200 증가합니다.", 500, 20));
		makeietm(7, Shop("힘의 돌", "공격력이 50 증가합니다.", 500, 20));
		makeietm(8, Shop("신속의 장화", "속도가 20 증가합니다.", 2500, 1));
		makeietm(9, Shop("사슬 갑옷", "방어력이 50 증가합니다. ", 2500, 1));
		makeietm(10, Shop("유령무희", "치명타 확률이 20프로 증가합니다.", 3500, 1));
		makeietm(11, Shop("무한의 대검", "치명타 배율이 1배 증가합니다.", 3500, 1));
		makeietm(12, Shop("보석 건틀릿", "스킬에 2배 치명타가 50프로 확률로 적용됩니다.", 5000, 1));
		makeietm(13, Shop("삼위일체", "속도가 30 방어력이 30 공격력이 300 체력이 300 마나가 300 증가합니다.", 3300, 1));
	}

	int mymoney(int i, Player& playr)
	{
		if (item[i].getPrice() <= playr.getGlod() && item[i].getNumber() > 0)
		{
			system("cls");
			cout << "구매에 성공하였습니다.\n";
			playr.setgold(item[i].getPrice());
			item[i].setNumber(1);
			return true;

		}
		else if (item[i].getNumber() == 0)
		{
			system("cls");
			cout << "품절입니다.\n";
			return false;
		}
		else
		{
			system("cls");
			cout << "소지금이 부족합니다.\n";
			return false;
		}

	}

	void showshop(Player& player)
	{
		int select = 0;


		do
		{
			cout << "구매할 아이템을 선택해주세요 다음 페이지는8번 나가기는 9번 입니다.\n";
			for (int i = 0; i < 7; i++)
			{
				cout << i + 1 << "번 ( " << item[i].getName() << " )\n옵션 : " << item[i].getInpo()
					<< "\n가격 :" << item[i].getPrice() << "원\n남은 갯수 : " << item[i].getNumber() << "\n" << endl;
			}

			cin >> select;
			switch (select)
			{
			case 1:
				if (mymoney(0, player))
				{
					player.sethppotion();
				
				}
				break;
			case 2:
				if (mymoney(1, player))
				{
					player.setmppotion();
				}

				break;
			case 3:
				if (mymoney(2, player))
				{
					player.sethppotion();
				}

				break;
			case 4:
				if (mymoney(3, player))
				{
					player.setmaxhp(50);
					player.setDef(5);
				}

				break;
			case 5:
				if (mymoney(4, player))
				{
					player.setAvoid(5);
				};
				break;
			case 6:
				if (mymoney(5, player))
				{
					player.setmaxmana(200);
				}

				break;
			case 7:
				if (mymoney(6, player))
				{
					player.setmaxhp(200);
				}
				break;
			case 8:
				break;
			case 9:
				break;
			default:
				system("cls");
				cout << "잘못된 입력입니다.\n" << endl;
			}
		} while (9 < select || 0 == select);

		if (select == 8)
		{
			do
			{
				cout << "구매할 아이템을 선택해주세요 나가기는 8번 입니다.\n";
				for (int i = 7; i < 14; i++)
				{
					cout << i - 6 << "번 ( " << item[i].getName() << " )\n옵션 : " << item[i].getInpo()
						<< "\n가격 :" << item[i].getPrice() << "\n남은 갯수 : " << item[i].getNumber() << "\n" << endl;
				}
				cin >> select;
				switch (select)
				{
				case 1:
					if (mymoney(7, player))
					{
						player.setatk(50);
					}
					break;
				case 2:
					if (mymoney(8, player))
					{
						player.setSpd(20);
					}
					break;
				case 3:
					if (mymoney(9, player))
					{
						player.setDef(50);
					}
					break;
				case 4:
					if (mymoney(10, player))
					{
						player.setCritChance(20);
					}
					break;
				case 5:
					if (mymoney(11, player))
					{
						player.setcritdmg(1);
					}
					break;
				case 6:
					if (mymoney(12, player))
					{
						player.skillcir();
					}
					break;
				case 7:
					if (mymoney(13, player))
					{
						player.setSpd(30);
						player.setDef(30);
						player.setatk(300);
						player.setmaxhp(300);
						player.setmaxmana(300);
					}
					break;
				case 8:
					break;
				default:
					system("cls");
					cout << "잘못된 입력입니다.\n" << endl;
				}

			} while (8 < select || 0 == select);


		}



	}











private:

	Shop item[14];

};



class Knight:public Player
{
public:
	Knight(string name):Player(name,1,500,500,100,100,40,20,15,2,25,20,100,0,0) {setupSkills();}

	virtual void setupSkills() override
	{
			MakeSkill(0, Skill("강타", "대상에게 공격력의 2배의 피해를 입힙니다.", 50,2,1));
			MakeSkill(1, Skill("재생의 바람", "자신의 체력을 회복합니다.", 50,4,1, true, false, false, false, true, false));
			MakeSkill(2, Skill("대지 가르기", "대상에게 공격력의 3배의 피해를 입힙니다.", 70, 3,2));
			MakeSkill(3, Skill("용의 일격", "대상에게 공격력의 4배의 방어력무시 치명타 피해를 가합니다", 150,4,5));

	}

private:


};
class Mage:public Player

{
public:
	Mage(string name):Player(name, 1, 250, 250, 300, 300, 20, 0, 25, 2,25, 35, 100, 0, 0) {setupSkills();}

	virtual void setupSkills() override
	{
		MakeSkill(0, Skill("화염구","적에게 공격력의 3배의 피해를 입힙니다.", 40, 3,1 ));
		MakeSkill(1, Skill("명상", "자신의 마나를 회복합니다.", 0, 8,2,true,false,false,false,false,true));
		MakeSkill(2, Skill("힐", "자신의 체력을 회복합니다.", 50, 4,3,true,false,false,false,true,false));
		MakeSkill(3, Skill("화염작렬", "적에게 공격력의 5배의 방어력무시 피해를 입힙니다.",200, 5,10,false,true));
	}
private:



};
class Rogue :public Player
{
public:
	Rogue(string name) :Player(name, 1, 300, 300, 150, 150, 25, 0, 50, 2, 45, 65, 100, 0, 0) { setupSkills(); }

	virtual void setupSkills() override
	{
		MakeSkill(0, Skill("급습", "적에게 방어무시 피해를 입힙니다.", 30, 1 ,1,false,true));
		MakeSkill(1, Skill("재생키트", "자신의 체력을 회복합니다.", 50,  4,2, true, false, false, false, true, false));
		MakeSkill(2, Skill("암살", "적에게 치명타 피해를 가합니다.", 50,1,3,false,true));
		MakeSkill(3, Skill("그림자 일격", "적에게 3배의 방어무시 피해를 입힙니다.", 100, 3,10,false,true));
	}
private:

};
class Gobiln/*고블린*/ :public Monster
{
public:
	Gobiln()
		:Monster("고블린",200,200,10,0,30,0,50,100){}

private:

};
class Golem/*골렘*/ :public Monster
{
public:
	Golem()
		:Monster("골렘",500,500,10,10,65,0,300,200) {}


private:

};
class witch/*마녀*/ :public Monster
{
public:
	witch()
		:Monster("마녀",600,600,15,25,200,30,500,450) {}


private:

};
class Troll/*트롤*/ :public Monster
{
public:
	Troll()
		:Monster("트롤",1500,1500,15,50,250,20,700,700) {}


private:

};
class Minotaur/*미노타우로스*/ :public Monster
{
public:
	Minotaur()
		:Monster("미노타우로스",2500,2500,15,100,350,35,900,1200) {}


private:
	
};
class Vampire/*뱀파이어*/:public Monster
{
public:
	Vampire()
		:Monster("뱀파이어",4000,4000,20,200,500,55,1200,2000) {}


private:

};
class Hydra/*히드라*/ :public Monster
{
public:
	Hydra()
		:Monster("히드라",10000,10000,25,300,800,55,2000,4000) {}


private:

};
class Dragon/*드래곤*/ :public Monster
{
public:
	Dragon()
		:Monster("드래곤",20000,20000,25,500,1000,80,4000,8000) {}

private:

};



void spawnGobiln(Player& player)
{
	Gobiln* newgobiln = new Gobiln();
	player.battle(*newgobiln);
}
void spawnGolem(Player& player)
{
	Golem* newGolem = new Golem();
	player.battle(*newGolem);
}
void spawnwitch(Player& player)
{
	witch* newwitch = new witch();
	player.battle(*newwitch);
}
void spawnTroll(Player& player)
{
	Troll* newTroll = new Troll();
	player.battle(*newTroll);
}
void spawnMinotaur(Player& player)
{
	Minotaur* newMinotaur = new Minotaur();
	player.battle(*newMinotaur);
}
void spawnVampire(Player& player)
{
	Vampire* newVampire = new Vampire();
	player.battle(*newVampire);
}
void spawnHydra(Player& player)
{
	Hydra* newHydra = new Hydra();
	player.battle(*newHydra);
}
void spawnDragon(Player& player)
{
	Dragon* newDragon = new Dragon();
	player.battle(*newDragon);
}

void Characterinpo()
{
	cout << "기사(Knight)는 깊은 던전의 어둠 속에서도 흔들리지 않는 존재입니다. \n";
	cout << "두터운 갑옷과 방패를 믿고, 압도적인 체력으로 적의 함정과 괴물들의 공격을 \n";
	cout << "강력한 방어 기술로 적의 공세를 버텨내며 한 걸음씩 전진합니다. \n";
	cout << "기사는 던전 깊숙한 곳에서조차 두려움 없이 맞서 싸우는 용사의 상징입니다.\n\n";

	cout << "마법사(Mage)는 던전 속에서 고요함을 유지하며, \n";
	cout << "압도적인 마나량과 강력한 마법으로 \n";
	cout << "던전을 가득 메운 적들을 멀리서 제압합니다. \n";
	cout << "힐과 명상을통한 유지력으로 미지의 심연을 탐험합니다.\n\n";

	cout << "돚거(Rogue)는 던전의 어둠 속에서 마치 그림자처럼 움직입니다. \n";
	cout << "날렵한 몸놀림과 민첩함으로 상대보다 많은 턴을 가져가며, \n";
	cout << "적의 약점을 포착하여 치명적인 일격을 가합니다. \n";
	cout << "던전의 깊숙한 곳에서도 적들은 도적의 빠른 공격과 \n";
	cout << "치명적인 일격을 결코 피할 수 없습니다. \n";
	cout << "====================================================\n";

}
Player* chooseCharacter()
{
	int select = 0;
	string Character;
	do
	{
		Characterinpo();
		cout << "캐릭터를 선택하세요\n1.번  기사 \n\n2.번  마법사\n\n3.번  돚거\n\n";
		cin >> select;
		switch (select)
		{
		case 1:
			Character = "기사";
			return new Knight(Character);
			break;
		case 2:
			Character = "마법사";
			return new Mage(Character);
			break;
		case 3:
			Character = "돚거";
			return new Rogue(Character);
			break;
		default:
			system("cls");
			cout << "잘못된 입력입니다.\n" << endl;
		}

	} while (3<select||0==select);
};
void training(Player& player) 
{	
	system("cls");
	int select = 0;
	while (0<player.gettraining()&&select<4)
	{

		do
		{
			player.status();
			cout << "훈련장 입니다 잔여 훈련횟수 만큼 훈련을 진행할수있습니다.\n" << endl;
			cout << "1. 체력훈련\n";
			cout << "2. 마나훈련\n";
			cout << "3. 공격훈련\n";
			cout << "4. 나간다\n";
			cout << "내 훈련 가능 횟수 :" << player.gettraining() << "회" << endl;
			cin >> select;
			switch (select)
			{
			case 1:
				system("cls");
				cout << "최대 체력을 10 만큼 올립니다.\n";
				player.setmaxhp(10);
				player.training();
				break;
			case 2:
				system("cls");
				cout << "최대 마나를 10 만큼 올립니다.\n";
				player.setmaxmana(10);
				player.training();
				break;
			case 3:
				system("cls");
				cout << "공격력을 2만큼 올립니다.\n";
				player.setatk(2);
				player.training();
				break;
			case 4:
				system("cls");
				break;
			default:
				system("cls");
				cout << "잘못된 입력입니다.\n"<< endl;
			}
		} while (4 < select || 0 >= select);

	}
	if (player.gettraining()<=0)
	{
		system("cls");
		cout << "더이상 훈련이 불가능합니다.\n";
		cout << "훈련 가능횟수" << player.gettraining() << "회\n";
	}
}
void shop(Player& player) 
{
	Item item;
	item.showshop(player);

}
void rested(Player& player) 
{
	system("cls");
	int select = 0;
	do
	{
		player.status();
		cout << "5원을 지불하고 휴식하시겠습니까? \n		1. 예		2. 아니요\n";
		cin >> select;
		switch (select)
		{
		case 1:
			if (player.getGlod()>=5)
			{
				system("cls");
				cout << "체력과 마나가 모두 회복됩니다.\n";
				player.relax(); player.setgold(5);
				break;
			}
			else
			{
				system("cls");
				cout << "소지금이 부족합니다\n";
				break;
			}
			break;
		case 2:
			system("cls");
			break;
		default:
			system("cls");
			cout << "잘못된 입력입니다.\n" << endl;
		}
	} while (2 < select || 0 == select);

}
void portal(Player& player)
{
	system("cls");
	player.status();
	int select = 0;
	do
	{
		cout << "여기는 포탈입니다. 각 번호에 해당하는 장소로 이동합니다.(로비는 9번입니다.)\n";
		cout << "1. 고블린의 숲		2. 무너진 유적		3. 마녀의 숲		4.트롤 서식지\n\n";
		cout << "5. 미궁의 던전		6. 사라진 성			7. 난파선		8.드래곤 둥지\n";
		cout << "최소레벨: 20		최소레벨: 30			최소레벨: 40		최소레벨: 60\n";
		cin >> select;
		switch (select)
		{
		case 1:
			spawnGobiln(player);
			break;
		case 2:
			spawnGolem(player);
			break;
		case 3:
			spawnwitch(player);
			break;
		case 4:
			spawnTroll(player);
			break;
		case 5:
			if (player.getlevel() >= 20)
			{
				spawnMinotaur(player);
				break;
			}
			else
			{
				system("cls");
				cout << "레벨이 부족합니다.\n내 레벨 : " << player.getlevel() << endl;
				break;
			}
			break;
		case 6:
			if (player.getlevel() >= 30)
			{
				spawnVampire(player);
				break;
			}
			else
			{
				system("cls");
				cout << "레벨이 부족합니다.\n내 레벨 : " << player.getlevel() << endl;
				break;
			}
			break;
		case 7:
			if (player.getlevel() >= 40)
			{
				spawnHydra(player);
				break;
			}
			else
			{
				system("cls");
				cout << "레벨이 부족합니다.\n내 레벨 : " << player.getlevel() << endl;
				break;
			}
			break;
		case 8:
			if (player.getlevel() >= 60)
			{
				spawnDragon(player);
				break;
			}
			else
			{
				system("cls");
				cout << "레벨이 부족합니다.\n내 레벨 : " << player.getlevel() << endl;
				break;
			}
			break;
		case 9:
			system("cls");
			cout << "로비로 이동합니다." << endl;
			break;
		default:
			system("cls");
			cout << "잘못된 입력입니다.\n" << endl;
		}
	} while (9 < select || 0 == select);

}
class Lobby {
public:
	Lobby(Player& p, Item& i) : player(p), item(i) {}

	void showMenu() {
		int select = 0;
		do {
			player.status();
			cout << "여기는 로비입니다.\n1. 훈련장  2. 상점 \n";
			cout << "3. 온천    4. 포탈  \n";
			cin >> select;
			switch (select) {
			case 1:
				training(player);
				break;
			case 2:
				system("cls");
				item.showshop(player);
				break;
			case 3:
				rested(player);
				break;
			case 4:
				portal(player);
				break;
			default:
				system("cls");
				cout << "잘못된 입력입니다.\n" << endl;
			}
		} while (select != 4);
	}

private:
	Player& player;
	Item& item;
};





int main() 
{
	Player* newplayer = chooseCharacter();
	Item item;
	item.shopset();
	system("cls");
	int coin = 1;
		Lobby lobby(*newplayer,item);

	
	while (coin >= 0) {
		lobby.showMenu();
	}
	


	delete newplayer;

}






