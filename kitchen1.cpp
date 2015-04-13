#include<iostream>                                                                                                                  
#include<string.h>
//#include<stdlib.h>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;

class Food{
	public:
		int click;
		int impress;
		unsigned long long int dis;
		int adid;
		int adver;
		int depth;
		int pos;
		int que;
		int key;
		int tit;
		int descr;
		int user;
};

class Drinks{
	public:
		unsigned long long int dis;
		int adver;
		int key;
		int tit;
		int descr;
};
class Bag{
	public:
		vector<Food> box;
};

bool compA(Food a, Food b)
{
	return(a.adid < b.adid);
}

bool compU(Food a, Food b)
{
	return(a.user < b.user);
}

bool compQ(Drinks a, Drinks b)
{
	if(a.dis < b.dis)
		return 1;
	else if(a.dis > b.dis)
		return 0;
	else
	{
		if(a.adver < b.adver)
			return 1;
		else if(a.adver > b.adver)
			return 0;
		else
		{
			if(a.key < b.key)
				return 1;
			else if(a.key > b.key)
				return 0;
			else
			{
				if(a.tit < b.tit)
					return 1;
				else if(a.tit > b.tit)
					return 0;
				else
				{
					if(a.descr < b.descr)
						return 1;
					else if(a.descr > b.descr)
						return 0;
					else
						return 0;
				}
			}
		}
	}
}
void print(vector<Food> box)
{
	for(vector<Food>::size_type i = 0; i < box.size(); i++)
	{
		printf("%d %d %llu %d %d %d %d %d %d %d %d %d\n", box[i].click, box[i].impress, box[i].dis, box[i].adid, box[i].adver, box[i].depth, box[i].pos, box[i].que, box[i].key, box[i].tit, box[i].descr, box[i].user);
	}
	return;
}
void get(int u, int a, int q, int p, int d, vector<Food> box)
{
	clock_t getbegin = clock();
	int x = 0, y = 0;
	for(vector<Food>::size_type i = 0; i < box.size(); i++)
	{
		if(box[i].adid < a)
			continue;
		else if(box[i].adid > a)
			break;
		if(box[i].que == q && box[i].pos == p && box[i].depth == d)
		{
			x += box[i].click;
			y += box[i].impress;
		}
	}
//	print(box);
	cout << "********************" << endl << x << " " << y << endl << "********************" << endl;
	clock_t getend = clock();
	cout << "getting time = " << (double)(getend - getbegin) / CLOCKS_PER_SEC<< endl;
	return;
}
void click(int u, vector<Food> box)
{
	cout << "********************" << endl;
	int tmpadid = -1, tmpque = -1;
	clock_t clicktm1 = clock();
	for(vector<Food>::size_type i = 0; i < box.size(); i++)
	{
		//		cout << i << " " << box[i].click << endl;
		if(box[i].click != 0 && (box[i].adid != tmpadid || box[i].que != tmpque))
		{
			cout <<  box[i].adid << " " << box[i].que << endl;
			tmpadid = box[i].adid;
			tmpque = box[i].que;
		}
	}
//	print(box);
	cout << "********************" << endl;
	clock_t clicktm2 = clock();
	cout << "clicking time = " << (double)(clicktm2 - clicktm1) / CLOCKS_PER_SEC<< endl;
	return;
}
void impressed(vector<Food> box1, vector<Food> box2, Bag arr3[], int u1, int u2)
{
	Drinks cup;
	vector<Drinks> soda;
	vector<Drinks> coke;
	clock_t time1 = clock();
	bool *adarr1 = new bool [23000000];
	bool *adarr2 = new bool [23000000];
	vector<int> add;
	bool x = 0;
	for(vector<Food>::size_type i = 0; i < box1.size(); i++)
		adarr1[box1[i].adid] = 1;
	for(vector<Food>::size_type j = 0; j < box2.size(); j++)
		adarr2[box2[j].adid] = 1;
	for(int k = 0; k < 23000000; k++)
		if(adarr1[k] & adarr2[k])
			add.push_back(k);
	for(vector<int>::size_type l = 0; l < add.size(); l++)
	{
		for(vector<Food>::size_type m = 0; m < arr3[add[l]].box.size(); m++)
		{
			if(arr3[add[l]].box[m].user == u1 || arr3[add[l]].box[m].user == u2)
			{
				if(x == 0)
					printf("%d\n", add[l]);
//				printf("     %llu %d %d %d %d\n", arr3[add[l]].box[m].dis, arr3[add[l]].box[m].adver, arr3[add[l]].box[m].key, arr3[add[l]].box[m].tit, arr3[add[l]].box[m].descr);
				cup.dis = arr3[add[l]].box[m].dis;
				cup.adver = arr3[add[l]].box[m].adver;
				cup.key = arr3[add[l]].box[m].key;
				cup.tit = arr3[add[l]].box[m].tit;
				cup.descr = arr3[add[l]].box[m].descr;
				coke.push_back(cup);
				x = 1;
			}
		}
		if(x == 1)
		{
			Drinks tmp;
			tmp.dis = tmp.adver = tmp.key = tmp.tit = tmp.descr = -1;
			sort(coke.begin(), coke.end(), compQ);
			for(vector<Drinks>::size_type n = 0; n < coke.size(); n++)
			{
				if(coke[n].dis != tmp.dis || coke[n].adver != tmp.adver || coke[n].key != tmp.key || coke[n].tit != tmp.tit || coke[n].descr != tmp.descr)
				{
					printf("     %llu %d %d %d %d\n", coke[n].dis, coke[n].adver, coke[n].key, coke[n].tit, coke[n].descr);	
					tmp.dis = coke[n].dis;
					tmp.adver = coke[n].adver;
					tmp.key = coke[n].key;
					tmp.tit = coke[n].tit;	
					tmp.descr = coke[n].descr;
				}
			}
			coke.clear();
		}
		x = 0;
	}
	clock_t time2 = clock();
	cout << "impressing time = " << (double)(time2 - time1) / CLOCKS_PER_SEC << endl;
}
void profit(vector<Food> box, double per)
{
//	print(box);
	clock_t profittime1 = clock();
	int *userarr = new int[24000000];
	double totcl = 0, totim = 0, ans = 0;
	int usenum = 0;
	for(vector<Food>::size_type i = 0; i < box.size(); i++)
	{
		if(i != 0)
		{
			if(box[i].user != box[i - 1].user)
			{
				ans = totcl / totim;
				if(ans >= per)
				{
					cout << usenum <<"'s ans = "<< ans << " per = " << per << endl;
					userarr[usenum++] = box[i - 1].user;
				}
				totcl = 0;
				totim = 0;
			}
		}
		totcl += box[i].click;
		totim += box[i].impress;
	}
	printf("********************\n");
	for(int j = 0; j < usenum; j++)
	{
		printf("%d\n", userarr[j]);
	}
	printf("********************\n");
	clock_t profittime2 = clock();
	cout << "profittime = " << (double)(profittime2 - profittime1) / CLOCKS_PER_SEC << endl;
	delete userarr;
}
int main(int argc, char** argv)
{
	int u, a, q, p, d, u1, u2;
	double per;
	clock_t start = clock();
//	Bag *arr = new Bag[24000000];
	//	eat(arr)
	//	printf("hahaha\n");
//	Food tmp; 

	/*	FILE *f = fopen("/tmp2/KDDCup2012/track2/kddcup2012track2.txt", "r");
	//	printf("Filein\n");
	time_t eattime1 = time(NULL);
	while(fscanf(f, "%d %d %llu %d %d %d %d %d %d %d %d %d", &tmp.click, &tmp.impress, &tmp.dis, &tmp.adid, &tmp.adver, &tmp.depth, &tmp.pos, &tmp.que, &tmp.key, &tmp.tit, &tmp.descr, &tmp.user) != EOF)
	{       
	//		printf("haha\n");
	arr[tmp.user].box.push_back(tmp);
	}
	time_t eattime2 = time(NULL);
	double eattime = difftime(eattime2, eattime1);
	cout << "eatting time = "<< eattime << endl;*/

	Food *tmparr = new Food[150000000];
	int k = 0;
	FILE *g = fopen(argv[1], "r");
	if(g == NULL)
		printf("haha\n");
	clock_t drinktime1 = clock();
	while(fscanf(g, "%d %d %llu %d %d %d %d %d %d %d %d %d", &tmparr[k].click, &tmparr[k].impress, &tmparr[k].dis, &tmparr[k].adid, &tmparr[k].adver, &tmparr[k].depth, &tmparr[k].pos, &tmparr[k].que, &tmparr[k].key, &tmparr[k].tit, &tmparr[k].descr, &tmparr[k].user) != EOF)
		k++;
	clock_t drinktime2 = clock();
	cout << "drinking time = " << (double)(drinktime2 - drinktime1) / CLOCKS_PER_SEC<< endl;

	clock_t teatime1 = clock();
	Bag *arr2 = new Bag[24000000];
	for(int l = 0; l < k; l++)
	{
		arr2[tmparr[l].user].box.push_back(tmparr[l]);
	}

	Bag *arr3 = new Bag[23000000];
	for(int l = 0; l < k; l++)
	{
		arr3[tmparr[l].adid].box.push_back(tmparr[l]);
	}
	clock_t teatime2 = clock();
	cout << "tea time = " << (double)(teatime2 - teatime1) / CLOCKS_PER_SEC << endl;

	clock_t sorttime1 = clock();
	for(int i = 0; i < 23907635; i++)
		sort(arr2[i].box.begin(), arr2[i].box.end(), compA);
	for(int i = 0; i < 22238280; i++)
		sort(arr3[i].box.begin(), arr3[i].box.end(), compU);
	clock_t sorttime2 = clock();
	cout << "sorting time = " << (double)(sorttime2- sorttime1) / CLOCKS_PER_SEC<< endl;

	char command[10];
	print(arr3[490234].box);
	while(scanf("%s", command) != EOF)
	{
		if(strcmp(command, "quit") == 0)
			break;
		if(strcmp(command, "get") == 0)
		{
			scanf("%d %d %d %d %d", &u, &a, &q, &p, &d);
			get(u, a, q, p, d, arr2[u].box);
		}
		else if(strcmp(command, "clicked") == 0)
		{
			scanf("%d", &u);
			click(u, arr2[u].box);
		}
		else if(strcmp(command, "profit") == 0)
		{
			scanf("%d %lf", &a, &per);
			profit(arr3[a].box, per);
		}
		else if(strcmp(command, "impressed") == 0)
		{
			scanf("%d %d", &u1, &u2);
			impressed(arr2[u1].box, arr2[u2].box, arr3, u1, u2);
		}
	}
	//	printf("%d %d %llu %d %d %d %d %d %d %d %d %d\n", arr[23907634].box[0].click, arr[23907634].box[0].impress, arr[23907634].box[0].dis, arr[23907634].box[0].adid, arr[23907634].box[0].adver, arr[23907634].box[0].depth, arr[23907634].box[0].pos, arr[23907634].box[0].que, arr[23907634].box[0].key, arr[23907634].box[0].tit, arr[23907634].box[0].descr, arr[23907634].box[0].user);
	clock_t end = clock();
	cout << "total time = " << (double)(end - start) / CLOCKS_PER_SEC<< endl;
	return 0;
}
