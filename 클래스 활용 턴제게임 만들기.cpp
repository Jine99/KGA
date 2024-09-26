//1.(�θ�)����Ŭ������ ����(ü��,���ݷ�...)
//2.2���̻��� �ڽ�Ŭ������ ����
//3.ex)�÷��̾� , ����
//�÷��̾�� ������ ���� ������ �����
//��get/set �̿��ϱ�
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
		cout << Name << "��(��)"<<dmg<<"�� ���� ���ظ� �޾ҽ��ϴ�." << endl;
		Hp -= dmg;
	} 



	void takeDmg(int dmg)
	{
		srand(time(0));
		int a = rand() % 100;
		
		if (a<=Avoid)
		{
			cout << Name << "��(��) ������ ȸ���Ͽ����ϴ�." << endl;
		}
		else if (dmg <= Def)
		{
			cout << "���ݷ��� �ʹ�����" << Name << "�� ������ ���� ���Ͽ����ϴ�." << endl;
			Hp -= 1;
		}
		else
		{
			cout << Name << "��(��) " << (dmg - Def) / 2 << "�� �������� �Ծ����ϴ�."<<endl;
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
		cout << "��ų " << skill.getSkillname() << "��(��) ����Ͽ����ϴ� \n";
		if (a<=skill.CritChance)
		{	
			cout << "��ų�� ġ��Ÿ�� ����˴ϴ�." << endl;
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
			cout << "����� ��ų�� �����ϼ���\n\n";
			for (int i = 0; i < 4; i++)
			{
				cout << i + 1<<"����ų ( " << skills[i].getSkillname() << " )\n��ų ���� : " << skills[i].getSkillinpo() 
					<<"\n���� ���� : "<<skills[i].getLevel()<<"����" << "\n�Ҹ� ���� : " << skills[i].getCostmana() <<"\n"<< endl;
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
				cout << "��ų " << skills[select-1].getSkillname() << "��(��) ����Ͽ����ϴ� \n";
				if (a <= skills[select-1].getcritChance())
				{
					cout << "��ų�� ġ��Ÿ�� ����˴ϴ�." << endl;
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
			 cout << Name << "�� ü���� " << a << " ��ŭ ȸ���Ǿ����ϴ�." << endl;
		 }
		 else
		 {
			 Hp = Maxhp;
			 cout << Name << "�� ü���� " << a << " ��ŭ ȸ���Ǿ����ϴ�." << endl;
		 }
	 }
	 void ManaRegen(int a) 
	 {
		 if (Maxmana > Mana + a)
		 {
			 Mana += a;
			 cout << Name << "�� ������ " << a << " ��ŭ ȸ���Ǿ����ϴ�." << endl;
		 }
		 else
		 {
			 Mana = Maxmana;
			 cout << Name << "�� ������ " << a << " ��ŭ ȸ���Ǿ����ϴ�." << endl;
		 }

	 }




	void status() 
	{
		cout << "=======================================================================\n";
		cout <<" " << Level << "����    " << Name << "\n";
		cout << "ü�� : " << Maxhp << " / " << Hp << "\n";
		cout << "���� : " << Maxmana << " / " << Mana << "\n";
		cout << "���ݷ�: " << Atk <<  " ����: " << Def<<"\n";
		cout << "�ӵ� : " << Spd << " ġ��Ÿ ����: " << CritDmg<<"��\n";
		cout << "ġ��Ÿ Ȯ��: " << CritChance << "% ȸ��: " << Avoid << "%\n";
		cout << "����ġ: " << Maxexp << " / " << Exp << "\n\n";
		cout << "������: " << Gold << "�� ���� �Ʒ� : " << trainingpoint << "ȸ\n";
		cout << "=======================================================================\n";
	}
	void battlestatus(Monster& monster) 
	{
		cout << "=======================================================================\n";
		cout << " " << Level << "����    " << Name << "					" << monster.getName() << "\n";
		cout << "ü�� : " << Maxhp << " / " << Hp << "			ü�� : " << monster.getMaxhp() << " / " << monster.getHp() << "\n";
		cout << "���� : " << Maxmana << " / " << Mana << "			���ݷ�: " << monster.getAtk() << " ����: " << monster.getDef() << "\n";
		cout << "���ݷ�: " << Atk << " ����: " << Def << "			�ӵ� : " << monster.getSpd() << " ȸ��" << monster.getAVoid() << "%\n";
		cout << "�ӵ� : " << Spd << " ġ��Ÿ ����: " << CritDmg << "��\n";
		cout << "ġ��Ÿ Ȯ��: " << CritChance << "% ȸ��: " << Avoid << "%\n";
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
			cout << "��ų�� ����ϱ� ���� ������ �����մϴ�\n ������ :" << Level << endl;
			return false;
		}

	}
	

	void showmyitem()
	{
		int select = 0;
		
		do
		{
			cout<< "1��  HP����\nü���� ���ݸ�ŭ ȸ�������ݴϴ�.\n���� ���� : "<<Hppotion<<"��\n";
			cout << "2��  MP����\n������ ���ݸ�ŭ ȸ�������ݴϴ�.\n���� ���� : " << mppotion << "��\n";
			cout << "3��  ���ǹ���\n1�ϰ� ���ݷ��� 100��ŭ �÷��ݴϴ�.\n���� ���� : " << atkpotion << "��\n";

			cin >> select;

			switch (select)
			{
			case 1:
				if (Hppotion > 0)
				{
					cout << "ü���� ���ݸ�ŭ ȸ���˴ϴ�." << endl;
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
					cout << "������ �����մϴ�."<<endl;
					break;
				}
			case 2:
				if (mppotion > 0)
				{
					cout << "������ ���ݸ�ŭ ȸ���˴ϴ�." << endl;
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
					cout << "������ �����մϴ�." << endl;
					break;
				}
			case 3:
				if (atkpotion > 0)
				{
					cout << "������ �����մϴ�." << endl;
					break;
				}
				else
				{
					cout << "������ �����մϴ�." << endl;
					break;
				}
			default:
				system("cls");
				cout << "�߸��� �Է��Դϴ�.\n" << endl;
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
			cout << "������ �����մϴ� ���� ���� :" << Mana << endl;
			return false;
		}

	}

	void PlayerAttack(Monster& monster)
	{
		srand(time(0));
		int critical = rand() % 100;

		if (critical < CritChance)
		{
			cout << "ũ��Ƽ�� ����!  " << CritDmg << "���� �������� ���ϴ�." << endl;
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
			cout << "\n1.����Ѵ�  (�� ���� : " << Def << ")\n2.ȸ���Ѵ�  (�� ȸ��Ȯ�� : " << Avoid << "%)" << endl;
			cin >> select;
			switch (select)
			{
			case 1:
				if (dmg <= Def)
				{
					system("cls");
					cout << "���忡 �����Ͽ����ϴ�." << 1 << "�� �������� �޽��ϴ�.\n";
					Hp -= 1;
				}
				else
				{
					system("cls");
					cout << "�� �����Ͽ�" << (dmg - Def) / 2 << "�� �������� �޽��ϴ�.\n";
					Hp -= (dmg - Def) / 2;
				}
				break;
			case 2:
				if (a <= Avoid)
				{
					system("cls");
					cout << "ȸ�ǿ� �����Ͽ����ϴ�." << endl;
				}
				else
				{
					system("cls");
					cout << "ȸ�ǿ� �����Ͽ����ϴ�." << endl;
					cout << dmg << "�� �������� �޽��ϴ�." << endl;
					Hp -= dmg;
				}
				break;
			default:
				system("cls");
				cout << "�߸��� �Է��Դϴ�.\n" << endl;

			}

		} while (2 < select || 0 == select);
	}
	void MonsterAttack(Monster& monster)
	{
		cout << monster.getName() << "��(��) ���� �� �õ��մϴ�." << endl;
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
					cout << "���� �Դϴ� �Ѱ��� �ൿ�� �����Ҽ� �ֽ��ϴ�." << endl;
					cout << "1. ���� 2.������ ���" << endl;
					cin >> select;
					system("cls");
					switch (select)
					{
					case 1:
						do
						{
							battlestatus(monster);
							cout << "1. �Ϲݰ��� 2. ��ųâ����" << endl;
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
								cout << "�߸��� �Է��Դϴ�.\n" << endl;
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
						cout << "�߸��� �Է��Դϴ�.\n" << endl;

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
			cout << "�����"<<monster.getName()<<"���� �׾����ϴ� �������� �������մϴ�." << endl;
			Hp = Maxhp/2;	delete& monster;
		}
		else if (monster.getHp()<=0)
		{
			cout << monster.getName() << "��(��) ���������ϴ�." << endl;
			cout << monster.getGold() << " ����" << monster.getXp() << " �� ����ġ�� ����ϴ�." << endl;
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
			cout << "�����մϴ� �������� �Ͽ����ϴ�." << endl;
			cout << " ����Ʈ 3���� ����ϴ�.  �ɷ�ġ�� �����Ͽ� ������ �ֽ��ϴ�.\n" << endl;
			while (Levelpoint > 0)
			{
				do
				{
					status();
					cout << "1.�ִ�ü�� 50 ����  2.�ִ븶�� 30 ����   3.���ݷ� 5 ���� \n" << endl;
					cout << "���� ����Ʈ : " << Levelpoint << "\n" << endl;
					cin >> select;

					switch (select)
					{
					case 1:
						system("cls");
						cout << "�ִ�ü���� 50 �����մϴ�.\n";
						Maxhp += 50;  Levelpoint -= 1;
						break;
					case 2:
						system("cls");
						cout << "�ִ븶���� 30 �����մϴ�.\n";
						Maxmana += 30;  Levelpoint -= 1;
						break;
					case 3:
						system("cls");
						cout << "���ݷ��� 5 �����մϴ�.\n";
						Atk += 5;	Levelpoint -= 1;
						break;
					default:
						system("cls");
						cout << "�߸��� �Է��Դϴ�.\n" << endl;
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
		makeietm(0, Shop("HP����", "ü���� ���ݸ�ŭ ȸ�������ݴϴ�.", 50, 1000));
		makeietm(1, Shop("MP����", "������ ���ݸ�ŭ ȸ�������ݴϴ�", 50, 1000));
		makeietm(2, Shop("���� ����", "���ݷ��� 1�ϰ� 100 �����մϴ�.", 100, 1000));
		makeietm(3, Shop("�ʺ��� ���", "ü��:50 ����:5�� �÷��ݴϴ�.", 0, 1));
		makeietm(4, Shop("ȸ�� ����", "ȸ��Ȯ���� 5���� �����մϴ�.", 250, 1));
		makeietm(5, Shop("������ ��", "�ִ� ������ 200 �����մϴ�.", 500, 20));
		makeietm(6, Shop("ü���� ��", "�ִ� ü���� 200 �����մϴ�.", 500, 20));
		makeietm(7, Shop("���� ��", "���ݷ��� 50 �����մϴ�.", 500, 20));
		makeietm(8, Shop("�ż��� ��ȭ", "�ӵ��� 20 �����մϴ�.", 2500, 1));
		makeietm(9, Shop("�罽 ����", "������ 50 �����մϴ�. ", 2500, 1));
		makeietm(10, Shop("���ɹ���", "ġ��Ÿ Ȯ���� 20���� �����մϴ�.", 3500, 1));
		makeietm(11, Shop("������ ���", "ġ��Ÿ ������ 1�� �����մϴ�.", 3500, 1));
		makeietm(12, Shop("���� ��Ʋ��", "��ų�� 2�� ġ��Ÿ�� 50���� Ȯ���� ����˴ϴ�.", 5000, 1));
		makeietm(13, Shop("������ü", "�ӵ��� 30 ������ 30 ���ݷ��� 300 ü���� 300 ������ 300 �����մϴ�.", 3300, 1));
	}

	int mymoney(int i, Player& playr)
	{
		if (item[i].getPrice() <= playr.getGlod() && item[i].getNumber() > 0)
		{
			system("cls");
			cout << "���ſ� �����Ͽ����ϴ�.\n";
			playr.setgold(item[i].getPrice());
			item[i].setNumber(1);
			return true;

		}
		else if (item[i].getNumber() == 0)
		{
			system("cls");
			cout << "ǰ���Դϴ�.\n";
			return false;
		}
		else
		{
			system("cls");
			cout << "�������� �����մϴ�.\n";
			return false;
		}

	}

	void showshop(Player& player)
	{
		int select = 0;


		do
		{
			cout << "������ �������� �������ּ��� ���� ��������8�� ������� 9�� �Դϴ�.\n";
			for (int i = 0; i < 7; i++)
			{
				cout << i + 1 << "�� ( " << item[i].getName() << " )\n�ɼ� : " << item[i].getInpo()
					<< "\n���� :" << item[i].getPrice() << "��\n���� ���� : " << item[i].getNumber() << "\n" << endl;
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
				cout << "�߸��� �Է��Դϴ�.\n" << endl;
			}
		} while (9 < select || 0 == select);

		if (select == 8)
		{
			do
			{
				cout << "������ �������� �������ּ��� ������� 8�� �Դϴ�.\n";
				for (int i = 7; i < 14; i++)
				{
					cout << i - 6 << "�� ( " << item[i].getName() << " )\n�ɼ� : " << item[i].getInpo()
						<< "\n���� :" << item[i].getPrice() << "\n���� ���� : " << item[i].getNumber() << "\n" << endl;
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
					cout << "�߸��� �Է��Դϴ�.\n" << endl;
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
			MakeSkill(0, Skill("��Ÿ", "��󿡰� ���ݷ��� 2���� ���ظ� �����ϴ�.", 50,2,1));
			MakeSkill(1, Skill("����� �ٶ�", "�ڽ��� ü���� ȸ���մϴ�.", 50,4,1, true, false, false, false, true, false));
			MakeSkill(2, Skill("���� ������", "��󿡰� ���ݷ��� 3���� ���ظ� �����ϴ�.", 70, 3,2));
			MakeSkill(3, Skill("���� �ϰ�", "��󿡰� ���ݷ��� 4���� ���¹��� ġ��Ÿ ���ظ� ���մϴ�", 150,4,5));

	}

private:


};
class Mage:public Player

{
public:
	Mage(string name):Player(name, 1, 250, 250, 300, 300, 20, 0, 25, 2,25, 35, 100, 0, 0) {setupSkills();}

	virtual void setupSkills() override
	{
		MakeSkill(0, Skill("ȭ����","������ ���ݷ��� 3���� ���ظ� �����ϴ�.", 40, 3,1 ));
		MakeSkill(1, Skill("���", "�ڽ��� ������ ȸ���մϴ�.", 0, 8,2,true,false,false,false,false,true));
		MakeSkill(2, Skill("��", "�ڽ��� ü���� ȸ���մϴ�.", 50, 4,3,true,false,false,false,true,false));
		MakeSkill(3, Skill("ȭ���۷�", "������ ���ݷ��� 5���� ���¹��� ���ظ� �����ϴ�.",200, 5,10,false,true));
	}
private:



};
class Rogue :public Player
{
public:
	Rogue(string name) :Player(name, 1, 300, 300, 150, 150, 25, 0, 50, 2, 45, 65, 100, 0, 0) { setupSkills(); }

	virtual void setupSkills() override
	{
		MakeSkill(0, Skill("�޽�", "������ ���� ���ظ� �����ϴ�.", 30, 1 ,1,false,true));
		MakeSkill(1, Skill("���ŰƮ", "�ڽ��� ü���� ȸ���մϴ�.", 50,  4,2, true, false, false, false, true, false));
		MakeSkill(2, Skill("�ϻ�", "������ ġ��Ÿ ���ظ� ���մϴ�.", 50,1,3,false,true));
		MakeSkill(3, Skill("�׸��� �ϰ�", "������ 3���� ���� ���ظ� �����ϴ�.", 100, 3,10,false,true));
	}
private:

};
class Gobiln/*���*/ :public Monster
{
public:
	Gobiln()
		:Monster("���",200,200,10,0,30,0,50,100){}

private:

};
class Golem/*��*/ :public Monster
{
public:
	Golem()
		:Monster("��",500,500,10,10,65,0,300,200) {}


private:

};
class witch/*����*/ :public Monster
{
public:
	witch()
		:Monster("����",600,600,15,25,200,30,500,450) {}


private:

};
class Troll/*Ʈ��*/ :public Monster
{
public:
	Troll()
		:Monster("Ʈ��",1500,1500,15,50,250,20,700,700) {}


private:

};
class Minotaur/*�̳�Ÿ��ν�*/ :public Monster
{
public:
	Minotaur()
		:Monster("�̳�Ÿ��ν�",2500,2500,15,100,350,35,900,1200) {}


private:
	
};
class Vampire/*�����̾�*/:public Monster
{
public:
	Vampire()
		:Monster("�����̾�",4000,4000,20,200,500,55,1200,2000) {}


private:

};
class Hydra/*�����*/ :public Monster
{
public:
	Hydra()
		:Monster("�����",10000,10000,25,300,800,55,2000,4000) {}


private:

};
class Dragon/*�巡��*/ :public Monster
{
public:
	Dragon()
		:Monster("�巡��",20000,20000,25,500,1000,80,4000,8000) {}

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
	cout << "���(Knight)�� ���� ������ ��� �ӿ����� ��鸮�� �ʴ� �����Դϴ�. \n";
	cout << "���Ϳ� ���ʰ� ���и� �ϰ�, �е����� ü������ ���� ������ �������� ������ \n";
	cout << "������ ��� ����� ���� ������ ���߳��� �� ������ �����մϴ�. \n";
	cout << "���� ���� ����� ���������� �η��� ���� �¼� �ο�� ����� ��¡�Դϴ�.\n\n";

	cout << "������(Mage)�� ���� �ӿ��� ������� �����ϸ�, \n";
	cout << "�е����� �������� ������ �������� \n";
	cout << "������ ���� �޿� ������ �ָ��� �����մϴ�. \n";
	cout << "���� ��������� ���������� ������ �ɿ��� Ž���մϴ�.\n\n";

	cout << "����(Rogue)�� ������ ��� �ӿ��� ��ġ �׸���ó�� �����Դϴ�. \n";
	cout << "������ ����� ��ø������ ��뺸�� ���� ���� ��������, \n";
	cout << "���� ������ �����Ͽ� ġ������ �ϰ��� ���մϴ�. \n";
	cout << "������ ����� �������� ������ ������ ���� ���ݰ� \n";
	cout << "ġ������ �ϰ��� ���� ���� �� �����ϴ�. \n";
	cout << "====================================================\n";

}
Player* chooseCharacter()
{
	int select = 0;
	string Character;
	do
	{
		Characterinpo();
		cout << "ĳ���͸� �����ϼ���\n1.��  ��� \n\n2.��  ������\n\n3.��  ����\n\n";
		cin >> select;
		switch (select)
		{
		case 1:
			Character = "���";
			return new Knight(Character);
			break;
		case 2:
			Character = "������";
			return new Mage(Character);
			break;
		case 3:
			Character = "����";
			return new Rogue(Character);
			break;
		default:
			system("cls");
			cout << "�߸��� �Է��Դϴ�.\n" << endl;
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
			cout << "�Ʒ��� �Դϴ� �ܿ� �Ʒ�Ƚ�� ��ŭ �Ʒ��� �����Ҽ��ֽ��ϴ�.\n" << endl;
			cout << "1. ü���Ʒ�\n";
			cout << "2. �����Ʒ�\n";
			cout << "3. �����Ʒ�\n";
			cout << "4. ������\n";
			cout << "�� �Ʒ� ���� Ƚ�� :" << player.gettraining() << "ȸ" << endl;
			cin >> select;
			switch (select)
			{
			case 1:
				system("cls");
				cout << "�ִ� ü���� 10 ��ŭ �ø��ϴ�.\n";
				player.setmaxhp(10);
				player.training();
				break;
			case 2:
				system("cls");
				cout << "�ִ� ������ 10 ��ŭ �ø��ϴ�.\n";
				player.setmaxmana(10);
				player.training();
				break;
			case 3:
				system("cls");
				cout << "���ݷ��� 2��ŭ �ø��ϴ�.\n";
				player.setatk(2);
				player.training();
				break;
			case 4:
				system("cls");
				break;
			default:
				system("cls");
				cout << "�߸��� �Է��Դϴ�.\n"<< endl;
			}
		} while (4 < select || 0 >= select);

	}
	if (player.gettraining()<=0)
	{
		system("cls");
		cout << "���̻� �Ʒ��� �Ұ����մϴ�.\n";
		cout << "�Ʒ� ����Ƚ��" << player.gettraining() << "ȸ\n";
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
		cout << "5���� �����ϰ� �޽��Ͻðڽ��ϱ�? \n		1. ��		2. �ƴϿ�\n";
		cin >> select;
		switch (select)
		{
		case 1:
			if (player.getGlod()>=5)
			{
				system("cls");
				cout << "ü�°� ������ ��� ȸ���˴ϴ�.\n";
				player.relax(); player.setgold(5);
				break;
			}
			else
			{
				system("cls");
				cout << "�������� �����մϴ�\n";
				break;
			}
			break;
		case 2:
			system("cls");
			break;
		default:
			system("cls");
			cout << "�߸��� �Է��Դϴ�.\n" << endl;
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
		cout << "����� ��Ż�Դϴ�. �� ��ȣ�� �ش��ϴ� ��ҷ� �̵��մϴ�.(�κ�� 9���Դϴ�.)\n";
		cout << "1. ����� ��		2. ������ ����		3. ������ ��		4.Ʈ�� ������\n\n";
		cout << "5. �̱��� ����		6. ����� ��			7. ���ļ�		8.�巡�� ����\n";
		cout << "�ּҷ���: 20		�ּҷ���: 30			�ּҷ���: 40		�ּҷ���: 60\n";
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
				cout << "������ �����մϴ�.\n�� ���� : " << player.getlevel() << endl;
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
				cout << "������ �����մϴ�.\n�� ���� : " << player.getlevel() << endl;
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
				cout << "������ �����մϴ�.\n�� ���� : " << player.getlevel() << endl;
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
				cout << "������ �����մϴ�.\n�� ���� : " << player.getlevel() << endl;
				break;
			}
			break;
		case 9:
			system("cls");
			cout << "�κ�� �̵��մϴ�." << endl;
			break;
		default:
			system("cls");
			cout << "�߸��� �Է��Դϴ�.\n" << endl;
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
			cout << "����� �κ��Դϴ�.\n1. �Ʒ���  2. ���� \n";
			cout << "3. ��õ    4. ��Ż  \n";
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
				cout << "�߸��� �Է��Դϴ�.\n" << endl;
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






