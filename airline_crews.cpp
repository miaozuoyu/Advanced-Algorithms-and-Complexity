#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


#define MAXN 100                 //MAXN��ʾX���Ϻ�Y���϶�����������ֵ
int nx,ny;                                       //x��y�����ж���ĸ���
int adj_matrix[MAXN][MAXN];                //�ڽӾ���g[i][j]Ϊ1��ʾ������
int cx[MAXN],cy[MAXN];        //cx[i],��ʾ������õ����ƥ���У���x������Ԫ��Xiƥ��ļ���Y�ж��������
                                                        //cy[i],��ʾ������õ����ƥ���У���y������Ԫ��Yiƥ��ļ���X�ж��������

//DFS�㷨�м�¼�������״̬������mk[i]=0��ʾδ���ʹ���Ϊ1��ʾ���ʹ�
int mk[MAXN];

//�Ӽ���X�еĶ�����u��������������޵Ĳ���Ѱ������·
//��������·ֻ���ǵ�ǰ��ƥ��������1
int path(int u,vector<vector<bool> > adj_matrix){
	
    for(int v=0;v<ny;++v){      //��������Yi����v
        if(adj_matrix[u][v] && !mk[v]){     //Y�ж���v��u�ڽӣ���û�з��ʹ�
            mk[v]=1;                        //����v

            //���vû��ƥ�䣬��ֱ�ӽ�vƥ���u�����v�Ѿ�ƥ���ˣ����Ǵ�cy[v],Ҳ���Ǵ�v֮ǰ�Ѿ�ƥ���x�������ҵ�һ������·�����������ס����v�Ѿ���¼���ʹ���
            //�����һ�������������򲻻�ݹ����
            if(cy[v]==-1 || path(cy[v],adj_matrix)){
                cx[u]=v;         //��Y��vƥ���X��u
                cy[v]=u;            //��X��uƥ���Y��v
                return 1;
            }
        }
    }
    return 0;                        //��������ڴ�u����������·���򷵻�0
}

int maxMatch(vector<vector<bool> > adj_matrix){        //�����ͼ���ƥ����������㷨

    int res=0;
    memset(cx,-1,sizeof(cx));        //��0ƥ�俪ʼ���㣬��cx��xy��Ԫ�ض���ʼ��Ϊ-1
    memset(cy,-1,sizeof(cy));
    for(int i=0;i<nx;++i){
        if(cx[i]==-1){                                    //��X������ÿ��û��ƥ��ĵ������ʼѰ������·
            memset(mk,0,sizeof(mk));
            res+=path(i,adj_matrix);
        }
    }
    return res;
}

vector<vector<bool> > ReadData() {
	int num_left, num_right;
	cin >> num_left >> num_right;
	vector<vector<bool> > adj_matrix(num_left, vector<bool>(num_right));
	for (int i = 0; i < num_left; ++i)
	  for (int j = 0; j < num_right; ++j) {
	    int bit;
	    cin >> bit;
	    adj_matrix[i][j] = (bit == 1);
	  }
	return adj_matrix;
}
int main() {

    /*adj_matrix[0][0]=1; adj_matrix[0][1]=1; adj_matrix[0][2]=0; adj_matrix[0][3]=1;
    adj_matrix[1][0]=0; adj_matrix[1][1]=1; adj_matrix[1][2]=0; adj_matrix[1][3]=0;
    adj_matrix[2][0]=0; adj_matrix[2][1]=0; adj_matrix[2][2]=0; adj_matrix[2][3]=0;
    
	for (int i = 0; i < nx; ++i)
	  for (int j = 0; j < ny; ++j) {
	    
	    
	    cout<<adj_matrix[i][j]<<endl;
	  }
    */
    vector<vector<bool> > adj_matrix = ReadData();
    nx = adj_matrix.size();
    ny = adj_matrix[0].size();
    int num= maxMatch(adj_matrix);
    //cout<<"num="<<num<<endl;
    for(int num=0;num<nx;++num){
    	if (cx[num]+1)
    	{
    		cout<<cx[num]+1<<' ';
		}
        else
        {
        	cout<<-1<<' ';
		}
    }

    return 0;
}

