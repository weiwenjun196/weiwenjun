#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<windows.h> 
using namespace std;
string color,kch,kch_wuqi,record[100010],record_wuqi[100010],record_changzhu[100010];
const string changzhu[8]={"迪卢克","琴","刻晴","莫娜","七七","提纳里","迪希雅","梦见月瑞希"};
const string changzhu_wuqi[10]={"阿莫斯之弓","和璞鸢","狼的末路","风鹰剑","四风原典","天空之翼","天空之傲","天空之脊","天空之刃","天空之卷"};
bool hh,wai,wai_wuqi,zb,fanhui,change_wuqi,kch_changzhu,record_wai[100010],record_wai_wuqi[100010];
int i,n,x,num4,k,num5,p5=6,p4=51,pwai=500,pro,pro_changzhu,num4xing,xiugai,numtot_5xing_wuqi,numtot_5xing,record_num[100010],record_num_wuqi[100010];
int pro_or,p5_changzhu=6,p4_changzhu=51,num4_changzhu,num5_changzhu,numtot_changzhu,p4_wuqi=60,p5_wuqi=7,pwai_wuqi=750,num5_wuqi,num4_wuqi,num4xing_wuqi;
int numtot_5xing_changzhu,record_num_changzhu[100010],num_changzhu;
double average,averagexianding,wailv,chuhuolv,numxianding,numwai,numtot,numxianding_wuqi,numwai_wuqi,numtot_wuqi;
int probability(){
	return rand()%10+rand()%10*10+rand()%10*100+1;
}
int probability_changzhu(bool x){
	if(x) return rand()%8;
	else return rand()%10;
} 
void chouka(int x){
	while(x--){
		pro=probability();
		num4++,num5++,numtot++,hh=0;
		if(num5>=74&&!zb)
			p5+=60;
		if(num5>=90||pro<=p5){
			if(probability()<=pwai||wai){
				cout<<"\033[33m("<<num5<<")『"<<kch<<"』\033[0m"<<endl;
				numxianding++,wai=0,record[numtot_5xing]=kch;
			}		
			else{
				pro_changzhu=probability_changzhu(1);
				cout<<"\033[33m("<<num5<<")歪『"<<changzhu[pro_changzhu]<<"』\033[0m"<<endl;
				numwai++,wai=1,record[numtot_5xing]=changzhu[pro_changzhu];
			}	
			if(!zb)
				p5=6;
			record_wai[numtot_5xing]=wai,record_num[numtot_5xing]=num5,num5=num4=0,numtot_5xing++;
			continue;
		}
		else if(num4>=10||pro<=p4){
			num4=0;
			cout<<"\033[35m4星\033[0m"<<endl;
			num4xing++;
			continue;
		} 
		cout<<"\033[34m3星\033[0m",hh=1;	
	}
	if(hh) cout<<endl;
}
void chouka_wuqi(int x){
	while(x--){
		pro=probability();
		num4_wuqi++,num5_wuqi++,numtot_wuqi++,hh=0;
		if(num5_wuqi>=63&&!zb){
			if(num5_wuqi<=73)
				p5_wuqi+=70;
			else
				p5_wuqi+=35;
		}
		if(num5_wuqi>=80||pro<=p5_wuqi){
			if(probability()<=pwai_wuqi||wai_wuqi){
				cout<<"\033[33m("<<num5_wuqi<<")『"<<kch_wuqi<<"』\033[0m"<<endl;
				numxianding_wuqi++,wai_wuqi=0,record_wuqi[numtot_5xing_wuqi]=kch_wuqi;
			}
			else{
				pro_changzhu=probability_changzhu(0);
				cout<<"\033[33m("<<num5_wuqi<<")歪『"<<changzhu_wuqi[pro_changzhu]<<"』\033[0m"<<endl;
				numwai_wuqi++,wai_wuqi=1,record_wuqi[numtot_5xing_wuqi]=changzhu_wuqi[pro_changzhu];
			}
			p5_wuqi=7;
			record_wai_wuqi[numtot_5xing_wuqi]=wai_wuqi,record_num_wuqi[numtot_5xing_wuqi]=num5_wuqi,num5_wuqi=num4_wuqi=0,numtot_5xing_wuqi++;
			continue;
		}
		else if(num4_wuqi>=10||pro<=p4_wuqi){
			num4_wuqi=0;
			cout<<"\033[35m4星武器\033[0m"<<endl;
			num4xing_wuqi++;
			continue;
		} 
		cout<<"\033[34m3星武器\033[0m",hh=1;
	}
	if(hh) cout<<endl;
}
void chouka_changzhu(int x){
	while(x--){
		pro=probability();
		num4_changzhu++,num5_changzhu++,numtot_changzhu++,hh=0;
		if(num5_changzhu>=74&&!zb)
			p5_changzhu+=60;
		if(num5_changzhu>=90||pro<=p5_changzhu){
			pro_or=(rand()%18<=7);
			if(pro_or){
				pro_changzhu=probability_changzhu(1);
				cout<<"\033[33m("<<num5_changzhu<<")『"<<changzhu[pro_changzhu]<<"』\033[0m"<<endl;
				num_changzhu++,record_changzhu[numtot_5xing_changzhu]=changzhu[pro_changzhu];
			}
			else{
				pro_changzhu=probability_changzhu(0);
				cout<<"\033[33m("<<num5_changzhu<<")『"<<changzhu_wuqi[pro_changzhu]<<"』\033[0m"<<endl;
				num_changzhu++,record_changzhu[numtot_5xing_changzhu]=changzhu_wuqi[pro_changzhu];
			}
			p5_changzhu=6;
			record_num_changzhu[numtot_5xing_changzhu]=num5_changzhu,num5_changzhu=num4_changzhu=0,numtot_5xing_changzhu++;
			continue;
		}
		else if(num4_changzhu>=10||pro<=p4_changzhu){
			num4_changzhu=0;
			cout<<"\033[35m4星\033[0m"<<endl;
			continue;
		}
		cout<<"\033[34m3星\033[0m",hh=1;
	}
	if(hh) cout<<endl;	
} 
void zhuangtai(bool x){
	if(!x&&!kch_changzhu) cout<<"\033[1;36m== ==当前状态〖角色〗== ==\033[0m"<<endl;
	else if(!kch_changzhu) cout<<"\033[1;36m== ==当前状态〖武器〗== ==\033[0m"<<endl;
	else{cout<<"\033[1;36m== ==当前状态〖常驻〗(功能完善中)== ==\033[0m"<<endl;return;}
	average=averagexianding=wailv=chuhuolv=0; 
	if(!x){
		if(numtot_5xing) average=numtot/(numtot_5xing);
		if(numxianding) averagexianding=numtot/numxianding;
		if(numxianding) wailv=numwai/numxianding*100;
		if(numtot) chuhuolv=(numtot_5xing)/numtot*100; 
	} 
	else{
		if(numtot_5xing_wuqi) average=numtot_wuqi/(numtot_5xing_wuqi);
		if(numxianding_wuqi) averagexianding=numtot_wuqi/numxianding_wuqi;
		if(numxianding_wuqi) wailv=numwai_wuqi/numxianding_wuqi*100;
		if(numtot_wuqi) chuhuolv=(numtot_5xing_wuqi)/numtot_wuqi*100;
	}
	cout<<"下次保底:";
	if(!x){
		if(wai==0)
			cout<<"小保底"<<num5<<"/90\t";
		else
			cout<<"大保底"<<num5<<"/90\t";
		cout<<"4星保底"<<num4<<"/10"<<endl;
		cout<<"常驻5星个数:"<<fixed<<setprecision(0)<<numwai<<"\t\t";
		cout<<"4星个数:"<<num4xing<<endl;
		cout<<"限定5星个数:"<<fixed<<setprecision(0)<<numxianding<<endl;
		cout<<"总抽数:"<<fixed<<setprecision(0)<<numtot<<endl;
	}
	else{
		if(wai_wuqi==0)
			cout<<"小保底"<<num5_wuqi<<"/80\t";
		else
			cout<<"大保底"<<num5_wuqi<<"/80\t";
		cout<<"4星保底"<<num4_wuqi<<"/10"<<endl; 
		cout<<"常驻5星个数:"<<fixed<<setprecision(0)<<numwai_wuqi<<"\t\t";
		cout<<"4星个数:"<<num4xing_wuqi<<endl;
		cout<<"限定5星个数:"<<fixed<<setprecision(0)<<numxianding_wuqi<<endl;
		cout<<"总抽数:"<<fixed<<setprecision(0)<<numtot_wuqi<<endl;
	}
	cout<<"平均出货抽数:"<<fixed<<setprecision(2)<<average<<endl;
	cout<<"平均出货抽数(限定5星):"<<fixed<<setprecision(2)<<averagexianding<<endl;
	cout<<"出货率:"<<fixed<<setprecision(2)<<chuhuolv<<"%"<<endl;
	cout<<"歪率:"<<fixed<<setprecision(2)<<wailv<<"%"<<endl;
}
void kachi(){
	cout<<"1.\033[1;36m杯装\033[0m之诗\033[1;36m『温迪』\033[0m"<<endl;
	cout<<"\033[1;36m『黎明破晓之史』\033[0m"<<endl<<endl;
	cout<<"2.\033[33m陵薮\033[0m市朝\033[33m『钟离』\033[0m"<<endl;
	cout<<" \033[33m『贯虹之槊』\033[0m"<<endl<<endl;
	cout<<"3.\033[1;35m影寂\033[0m天下人\033[1;35m『雷电将军』\033[0m"<<endl;
	cout<<" \033[1;35m『薙草之稻光』\033[0m"<<endl<<endl;
	cout<<"4.\033[1;32m月草\033[0m的赐慧\033[1;32m『纳西妲』\033[0m"<<endl;
	cout<<" \033[1;32m『千夜浮梦』\033[0m"<<endl<<endl;
	cout<<"5.\033[1;34m众水\033[0m的颂诗\033[1;34m『芙宁娜』\033[0m"<<endl;
	cout<<" \033[1;34m『静水流涌之辉』\033[0m"<<endl<<endl;
	cout<<"6.\033[1;31m宿古\033[0m的赫炎\033[1;31m『玛薇卡』\033[0m"<<endl;
	cout<<" \033[1;31m『焚曜千阳』\033[0m"<<endl<<endl; 
	cout<<"7.\033[1m常驻卡池-奔行世间\033[0m"<<endl<<endl; 
	cout<<"8.\033[1;33m自定义角色/武器\033[0m"<<endl<<endl; 
	while(1){
		cout<<"请选择卡池:";
		if(!(cin>>k)||k<1||k>8){
			cin.clear(),cin.ignore(1000,'\n');
			cout<<"\033[31m输入无效_请输入1--8之间数字!\033[0m"<<endl;
			continue;
		}
		if(k==1) kch="温迪",kch_wuqi="黎明破晓之史",color="\033[1;36m"; 
		else if(k==2) kch="钟离",kch_wuqi="贯虹之槊",color="\033[33m";
		else if(k==3) kch="雷电将军",kch_wuqi="薙草之稻光",color="\033[1;35m";
		else if(k==4) kch="纳西妲",kch_wuqi="千夜浮梦",color="\033[1;32m";
		else if(k==5) kch="芙宁娜",kch_wuqi="静水流涌之辉",color="\033[1;34m";
		else if(k==6) kch="玛薇卡",kch_wuqi="焚曜千阳",color="\033[1;31m";
		else if(k==7) kch="常驻",color="\033[1m",change_wuqi=0,kch_changzhu=1;
		else if(k==8){
			cout<<"请输入卡池角色名称:";
			cin>>kch;
			cout<<"请输入角色武器名称:";
			cin>>kch_wuqi; 
			color="\033[1;33m"; 
		}
		if(k!=7) kch_changzhu=0;
		cout<<color<<"==卡池角色已切换为『"<<kch<<"』==\033[0m"<<endl;
		break;
	} 
	return;
}
void zuobi(int x){
	if(x==1){
		cout<<"请输入5星概率(0--100):";
		cin>>xiugai;
		p5=xiugai*10,zb=1;
		cout<<"\033[32m//5星概率已修改为"<<xiugai<<"%//\033[0m"<<endl;
	}
	else if(x==2){
		cout<<"请输入歪率(0--100):";
		cin>>xiugai; 
		pwai=1000-xiugai*10,zb=1;
		cout<<"\033[32m//歪概率已修改为"<<xiugai<<"%//\033[0m"<<endl;
	}
	else if(x==3){
		p4=51,p5=6,pwai=500,zb=0;
		cout<<"\033[32m//概率已重置//\033[0m"<<endl;
	}
	else if(x==0){
		cout<<"\033[32m//已返回//\033[0m"<<endl;
		fanhui=1;
	}	
	return;	
}
void record_output(bool x){
	if(!x&&!kch_changzhu){
		if(!numtot_5xing)
			cout<<"\033[1;36m//暂无记录//\033[0m"<<endl;
		for(i=0;i<numtot_5xing;i++){
			cout<<"\033[33m("<<record_num[i]<<")";
			if(record_wai[i])
				cout<<"歪"; 
			cout<<"『"<<record[i]<<"』\033[0m"<<endl;
		}
	} 
	else if(!kch_changzhu){
		if(!numtot_5xing_wuqi)
			cout<<"\033[1;36m//暂无记录//\033[0m"<<endl;
		for(i=0;i<numtot_5xing_wuqi;i++){
			cout<<"\033[33m("<<record_num_wuqi[i]<<")";
			if(record_wai_wuqi[i])
				cout<<"歪"; 
			cout<<"『"<<record_wuqi[i]<<"』\033[0m"<<endl;
		}
	}
	else{
		if(!numtot_5xing_changzhu)
			cout<<"\033[1;36m//暂无记录//\033[0m"<<endl;
		for(i=0;i<numtot_5xing_changzhu;i++){
			cout<<"\033[33m("<<record_num_changzhu[i]<<")『"<<record_changzhu[i]<<"』\033[0m"<<endl;
		}
	}
}
int main(){
	srand(time(0));
	cout<<"╔═══════════════════════════════╗"<<endl; 
	cout<<"║\033[1;36m ==【原神抽卡模拟器/测试版】== \033[0m║"<<endl;
	cout<<"╚═══════════════════════════════╝"<<endl;
	cout<<"作者\033[1;36m『weiwenjun』\033[0m"<<endl<<endl; 
	system("pause"),system("cls");
	kachi();
	while(1){
		system("pause"),system("cls");
		if(!kch_changzhu){
			if(!change_wuqi)cout<<color<<"== ==当前卡池〖角色〗/『"<<kch<<"』== ==\033[0m"<<endl;
			else cout<<color<<"== ==当前卡池〖武器〗/『"<<kch_wuqi<<"』== ==\033[0m"<<endl;
		}
		else cout<<color<<"== ==当前卡池〖常驻〗== ==\033[0m"<<endl;
		cout<<"1.单抽"<<endl;
		cout<<"2.十连"<<endl;
		cout<<"3.状态"<<endl;
		cout<<"4.自定义抽数"<<endl;
		cout<<"5.作弊"<<endl;
		cout<<"6.查看抽卡记录"<<endl; 
		cout<<"7.切换卡池"<<endl;
		cout<<"8.重置模拟器"<<endl;
		if(!kch_changzhu){
			if(!change_wuqi) cout<<color<<"== ==9.切换为武器池『"<<kch_wuqi<<"』== ==\033[0m"<<endl;
			else cout<<color<<"== ==9.切换为角色池『"<<kch<<"』== ==\033[0m"<<endl;		
		}
		cout<<"0.结束模拟"<<endl;
		if(!(cin>>n)||n<0||n>9||kch_changzhu&&n==9){
			cin.clear(),cin.ignore(1000,'\n');
			if(!kch_changzhu) cout<<"\033[31m输入无效_请输入0--9之间数字!\033[0m"<<endl;
			else cout<<"\033[31m输入无效_请输入0--8之间数字!\033[0m"<<endl;
			continue;
		}
		if(n==1){
			if(!kch_changzhu){
				if(!change_wuqi) chouka(1);
				else chouka_wuqi(1);
			}
			else chouka_changzhu(1);
		}
		else if(n==2){
			if(!kch_changzhu){
				if(!change_wuqi) chouka(10);
				else chouka_wuqi(10);
			}
			else chouka_changzhu(10);
		}
		else if(n==3){
			zhuangtai(change_wuqi);
		}
		else if(n==4){
			while(1){
				cout<<"请输入次数(0--100000):";
				if(!(cin>>x)||x<0||x>100000){
					cin.clear(),cin.ignore(1000,'\n');
					cout<<"\033[31m输入无效_请输入0--100000数字!\033[0m"<<endl;
					continue;
				}
				if(!kch_changzhu){
					if(!change_wuqi) chouka(x);
					else chouka_wuqi(x);
				}
				else chouka_changzhu(x);
				break; 
			}
		}
		else if(n==5){
			cout<<"\033[1;33m//修改器//\033[0m"<<endl;
			cout<<"1.修改5星概率(当前"<<p5/10.0<<"%)"<<endl;
			cout<<"2.修改歪率(当前"<<pwai/10.0<<"%)"<<endl;
			cout<<"3.重置概率"<<endl;
			cout<<"0.返回"<<endl;
			while(1){
				if(!(cin>>xiugai)||xiugai<0||xiugai>3){
					cin.clear(),cin.ignore(1000,'\n');
					cout<<"\033[31m输入无效_请输入0--3之间数字!\033[0m"<<endl;
					continue;
				}
				zuobi(xiugai);
				if(fanhui){
					fanhui=0;
					break;
				}
			}
		}
		else if(n==6){
			record_output(change_wuqi);
		}
		else if(n==7){
			kachi();
		}
		else if(n==8){
			num4=num5=wai=num4xing=numwai=numxianding=numtot=numtot_5xing=zb=change_wuqi=0,pwai=500,p4=51,p5=6; 
			num5_wuqi=num4_wuqi=wai_wuqi=num4xing_wuqi=numwai_wuqi=numxianding_wuqi=numtot_wuqi=numtot_5xing_wuqi=0,pwai_wuqi=750,p4_wuqi=60,p5_wuqi=7;
			num4_changzhu=num5_changzhu=numtot_changzhu=num_changzhu=numtot_5xing_changzhu=0,p5_changzhu=6,p4_changzhu=51;
			cout<<"\033[32m//模拟器已重置//\033[0m"<<endl;
			system("pause"),system("cls");
			kachi();
		}
		else if(n==9){
				if(!change_wuqi) 
					change_wuqi=1,cout<<color<<"==已切换为武器池『"<<kch_wuqi<<"』==\033[0m"<<endl;
				else
					change_wuqi=0,cout<<color<<"==已切换为角色池『"<<kch<<"』==\033[0m"<<endl;
		}
		else if(n==0){
			cout<<"\033[1;36m== ==感谢使用== ==\033[0m"<<endl;
			cout<<"\033[1;36m下次再见,旅行者!\033[0m"<<endl;
			return 0;
		} 
	}
}
