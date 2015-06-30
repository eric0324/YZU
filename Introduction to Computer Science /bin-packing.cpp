/**********************************************************************************/
/*  problem:bin-packing problem                                                   */
/*  元智大學資工 2c 吳冠賢 1013353                                                  */
/**********************************************************************************/

#include <iostream>
using namespace std;

#define nBox 3 //箱子有多少個
#define nGood 3 //物品有多少的

int main()
{
	float fGoodsSize[nGoods]; //宣告每一個物品大小  
	float fBox[nBox];
	int nBoxIn[nBox][nGoods]; //紀錄箱子屬於哪一個

	int i = 0, j = 0;

	//輸入資料
	cout << "輸入 Good size : " << endl;

	for (i = 0; i != nGoods; i++)
		cin >> fGoodsSize[i];

	float fBoxSize; //宣告箱子大小
	cout << "輸入Box size : " << endl;
	cin >> fBoxSize;

	// 告訴fBox它array size
	for (i = 0; i != nBox; i++)
		fBox[i] = fBoxSize; 

	int nGoodsNo = 1; //物品編號初始值

	//丟物品進箱子
	for (i = 0; i != nGoods; i++)
		for (j = 0; j != nBox; j++)
		{
			if (fGoodsSize[i] <= fBox[j]) // 當物品大小比箱子大小還小或等於時 ,放得進去,所以存入
			{
				fBox[j] -= fGoodsSize[i]; //箱子Size - 物品Size
				nBoxIn[j][i] = nGoodsNo; //紀錄物品歸屬於哪一個箱子
				nGoodsNo++; //物品編號+1
				break;
			}
	}

	//紀錄使用多少箱子
	int nUseBoxCount = 0; 
	for (i = 0; i != nBox; i++)
	if (fBox[i] != fBoxSize)
		++nUseBoxCount;

	//把結果印出來
	cout << "使用箱子數 : " << nUseBoxCount << endl;

	for (i = 0; i != nBox; i++)
	{
		cout << "箱子" << (i + 1) << " 裝了物品 :";
		for (j = 0; j != nGoods; j++)
		{
			if (nBoxIn[i][j] > 0)
			{
				cout << " " << nBoxIn[i][j];
			}
		}
		cout << endl;
	}
	system("pause");
}