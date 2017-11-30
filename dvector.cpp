#include <iostream>
using namespace std;

static int N, M, S;

struct Topologi
{
	int u;
	int v;
};

struct Skenario
{	
	int x;
	int y;
};

class RoutingTable 
{
public:
	struct Info
	{
		int distance;
		int nextHop;
	};

	struct Node
	{
		Info* nodeInfo;
	};

	Node* RT;

	RoutingTable()
	{
		int i;

		RT = new Node[N+1];
		for(i=1; i<=N; i++)
		{
			this->RT[i].nodeInfo = new Info[N+1];
		}
	};

	void Initiate(Topologi* top)
	{
		int i,j;

		for(i=1; i<=N; i++)
		{
			for(j=1; j<=N; j++)
			{
				if(i==j)
				{
					this->RT[i].nodeInfo[j].distance = 0;
					this->RT[i].nodeInfo[j].nextHop = j;
				}
				else
				{
					this->RT[i].nodeInfo[j].distance = -1;
					this->RT[i].nodeInfo[j].nextHop = -1;
				}
			}
		}

		for(i=1; i<=M; i++)
		{
			/* pada routing table u ditambahkan info node v*/
			this->RT[top[i].u].nodeInfo[top[i].v].distance = 1;
			this->RT[top[i].u].nodeInfo[top[i].v].nextHop = top[i].v;
			/* pada routing table v ditambahkan info node u*/
			this->RT[top[i].v].nodeInfo[top[i].u].distance = 1;
			this->RT[top[i].v].nodeInfo[top[i].u].nextHop = top[i].u;
		}
	}



	void Print()
	{
		int i,j;

		for(i=1; i<=N; i++)
		{
			for(j=1; j<=N; j++)
			{
				cout << this->RT[i].nodeInfo[j].distance << " " << this->RT[i].nodeInfo[j].nextHop << endl;
			}
		}
	}
};

int main() {
	RoutingTable* A;
	Topologi* top;
	Skenario* sken;
	int i,j;

	cin >> N >> M;

	cout << "CHECKPOINT 1: READ SKENARIO DAN TOPOLOGI"<<endl;

	top = new Topologi[M+1];
	for(i=1; i<=M; i++)
	{
		cin >> top[i].u >> top[i].v;
	}
	cin >> S;
	sken = new Skenario[S+1];
	for(i=1; i<=S; i++)
	{
		cin >> sken[i].x >> sken[i].y;
	}

	/* tes output */
	cout << "topologi" << endl;
	for(i=1; i<=M; i++)
	{
		cout << top[i].u << " " << top[i].v << endl;
	}
	cout << "skenario" << endl;
	for(i=1; i<=S; i++)
	{
		cout << sken[i].x << " " << sken[i].y << endl;
	}

	cout << "CHECKPOINT 2: INISIALISASI ROUTING TABLE"<<endl;

	A = new RoutingTable();
	A->Initiate(top);
	
	/* tes output inisialisasi routing table*/
	for(i=1; i<=N; i++)
	{
		cout << "Node " << i << endl;
		for(j=1; j<=N; j++)
		{
			cout << j << " " << A->RT[i].nodeInfo[j].distance << " " << A->RT[i].nodeInfo[j].nextHop << endl;
		}
		cout << endl;
	}

	cout << "CHECKPOINT 3: TRANSFER KNOWLEDGE"<<endl;



	/* tes output inisialisasi dengan method Print() */
	//A->Print();

	/* ITERASI SEMUA SKENARIO */
	for(i=1;i<=S;i++){
		cout<< "kasus "<< i <<" :"<<endl;
		cout << sken[i].x << " " << sken[i].y << endl;

		for(j = 1;j<=N;j++){
			//KASUS AD YG TIDAK TAHU
			if(A->RT[sken[i].x].nodeInfo[j].distance == -1 && A->RT[sken[i].y].nodeInfo[j].distance != -1){
				A->RT[sken[i].x].nodeInfo[j].distance += A->RT[sken[i].y].nodeInfo[j].distance;
				A->RT[sken[i].x].nodeInfo[j].nextHop = sken[i].y;
			}

			//KASUS AD YG BEDA INFORMASINYA
			if(A->RT[sken[i].x].nodeInfo[j].distance != -1 && A->RT[sken[i].y].nodeInfo[j].distance != -1 && A->RT[sken[i].x].nodeInfo[j].nextHop != A->RT[sken[i].y].nodeInfo[j].nextHop ){
				if(A->RT[sken[i].x].nodeInfo[j].distance < A->RT[sken[i].y].nodeInfo[j].distance){
					A->RT[sken[i].y].nodeInfo[j].distance = A->RT[sken[i].x].nodeInfo[j].distance + 1;
					A->RT[sken[i].y].nodeInfo[j].nextHop = A->RT[sken[i].x].nodeInfo[j].nextHop;
				}
			}
		}
	}

	/* tes output */
	for(i=1; i<=N; i++)
	{
		cout << "Node " << i << endl;
		for(j=1; j<=N; j++)
		{
			cout << j << " " << A->RT[i].nodeInfo[j].distance << " " << A->RT[i].nodeInfo[j].nextHop << endl;
		}
		cout << endl;
	}

	/*  */

	return 0;
}