#include <iostream>
#include<string.h>
#include<windows.h>
#include<conio.h>
#define escribir cout
#define leer cin
/* ALGORITMO CREATED FOR I GET RESULTS EXPECIFICS EXPENSES MENSUALES AND OTHERS*/
using namespace std;

void cordxy(int x,int y)
{
COORD coord;
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);	
}

void cuadropantalla(int ancho,int largo){
	int i;
	//columna
	for(i=0;i<ancho;i++){
		cordxy(5,i);escribir<<"\263";
		cordxy(largo,i);escribir<<"\263";
	}
	//fila
	for(i=6;i<largo;i++){
		cordxy(i,0);escribir<<"\304";
		cordxy(i,ancho);escribir<<"\304";
	}
	//esquina superior izquierdo
	cordxy(5,0);escribir<<"\332";
	//esquina superior derecho
	cordxy(largo,0);escribir<<"\277";
	//esquina inferior derecho
	cordxy(5,ancho);escribir<<"\300";
	//esquina inferior izquierda
	cordxy(largo,ancho);escribir<<"\331";
}

struct expensess{
	char codigo[10];
	char mes[15];
	char activo;
	float basicsueld;
	float renthome,expenses,serverhome,others,cash,memoum,mysoon,mefood,telephone,medplanific,myhome;
};
int main(int argc, char** argv) {
	system("color f2");
	int opcion=1;
	expensess mounth;
	FILE *archivo;
	while(opcion!=0){
		system("cls");
		cuadropantalla(22,78);
		system("color a1");
		cordxy(10,5);escribir<<" MENU";
		cordxy(7,7);escribir<<" 1. ingresar datos: "<<endl;
		cordxy(7,8);escribir<<" 2. visualizar dato: "<<endl;
		cordxy(7,9);escribir<<" 3. modificar datos: "<<endl;
		cordxy(7,10);escribir<<" 4. eliminar datos: "<<endl;
		cordxy(7,11);escribir<<" 0. salir: "<<endl;
		cordxy(7,12);escribir<<" seleccione una opcion: "<<endl;
		cordxy(30,12);leer>>opcion;
		switch(opcion){
			case 1:{
				system("cls");
				system("color f0");
				cuadropantalla(22,78);
				expensess mounth;
                FILE *archivo;
				leer.ignore(256,'\n');
				cordxy(6,1);escribir<<" have a good day churro, you are the best "<<endl;
				cordxy(6,2);escribir<<" write the codigo: "<<endl;
            	cordxy(7,3);leer.getline(mounth.codigo,10);
	            cordxy(6,4);escribir<<" write the mounth: "<<endl;
            	cordxy(7,5);leer.getline(mounth.mes,15);
            	cordxy(6,6);escribir<<" my basic salary: "<<endl;
	            cordxy(7,7);leer>>mounth.basicsueld;
	            cordxy(6,8);escribir<<" Dinner to pay for the housemoum: "<<endl;
	            cordxy(7,9);leer>>mounth.memoum;
            	cordxy(6,10);escribir<<" Dinner to pay for expenses of mysoon:  "<<endl;
	            cordxy(7,11);leer>>mounth.mysoon;
	            cordxy(6,12);escribir<<" Dinner to pay for the my food server: "<<endl;
	            cordxy(7,13);leer>>mounth.mefood;
	            cordxy(6,14);escribir<<" Dinner to pay for the rent home: "<<endl;
	            cordxy(7,15);leer>>mounth.renthome;
                cordxy(6,16);escribir<<" Dinner to pay for the my server home: "<<endl;
	            cordxy(7,17);leer>>mounth.serverhome;
	            cordxy(6,18);escribir<<" Dinner to pay for the telephone mobile server: "<<endl;
	            cordxy(7,19);leer>>mounth.telephone;
	            cordxy(6,20);escribir<<" Dinner to pay for the medicinalplanific: "<<endl;
	            cordxy(7,21);leer>>mounth.medplanific;
	            cordxy(6,22);escribir<<" others expenses :"<<endl;
	            cordxy(6,23);leer>>mounth.others;
	            cordxy(6,22);mounth.activo='s';
	            archivo=fopen("expenses_mounth.txt", "ab");
	            if (archivo==NULL){
	            	archivo=fopen("expenses_mounth.txt", "wb");}
	            	fwrite(&mounth,sizeof(mounth),1,archivo);
	            	rewind(archivo),
	            	fclose(archivo);
	            	break;
			    	}
			case 2:{
					system("cls");
					system("color a0");
					cuadropantalla(22,78);
					char google[5];
	                cordxy(7,5);escribir<<" ingrese el codigo a buscar: "<<endl;
	                cordxy(7,6);leer>>google;
					archivo=fopen("expenses_mounth.txt", "rb");
					rewind(archivo);
					int cod=0;
					int reg1=9;
					int reg=1;
					leer.ignore(256,'\n');
					while(fread(&mounth,sizeof(mounth),1,archivo)){
						if (strcmp(google,mounth.codigo)==0 && mounth.activo=='s' ){
                            mounth.myhome=((mounth.renthome+mounth.serverhome)/3);
	                        mounth.expenses=(mounth.telephone+mounth.myhome+mounth.mysoon+mounth.others+mounth.medplanific+mounth.mefood+mounth.memoum);
	                        mounth.cash=(mounth.basicsueld-mounth.expenses);
	                        
	                        cordxy(7,8);escribir<<"REG: ";
                            cordxy(7,reg1);escribir<<reg<<endl;
                            cordxy(15,8);escribir<<"MOUNTH: ";
				            cordxy(15,reg1);escribir<<mounth.mes<<endl;
			                cordxy(30,8);escribir<<"BASICSALARY: ";
				            cordxy(30,reg1);escribir<<mounth.basicsueld<<endl;
		                    cordxy(46,8);escribir<<"EXPENSES: ";
				            cordxy(46,reg1);escribir<<mounth.expenses<<endl;
				            cordxy(62,8);escribir<<"CASH: ";
				            cordxy(62,reg1);escribir<<mounth.cash<<endl;
				            cod=1;
                            reg++;
                            reg1++;
						}
				    }
				      if (cod==0){
		                 cordxy(12,12);escribir<<" no existe "<<endl;
		                }
					system("pause");
					fclose(archivo);
					    break;
				   }
			case 3:{
	 	           system("cls");
	 	           system("color b8");
			        cuadropantalla(22,78);
			       char google[5];
			       float newexpenses;
			       char newcodigo[10];
	               cordxy(7,2);escribir<<" write the codigo of registro: "<<endl;
	               cordxy(8,3);leer>>google;
	               archivo=fopen("expenses_mounth.txt", "rb+");
                   rewind(archivo);
           	        int cod=0;
					int reg1=9;
					int reg=1;
					int change=1;
					leer.ignore(256,'\n');
					while(fread(&mounth,sizeof(mounth),1,archivo)){
						if (strcmp(google,mounth.codigo)==0 && mounth.activo=='s' ){
                            mounth.myhome=((mounth.renthome+mounth.serverhome)/3);
	                        mounth.expenses=(mounth.telephone+mounth.myhome+mounth.mysoon+mounth.others+mounth.medplanific+mounth.mefood+mounth.memoum);
	                        mounth.cash=(mounth.basicsueld-mounth.expenses);
                            cordxy(7,8);escribir<<"REG: ";
                            cordxy(7,reg1);escribir<<reg<<endl;
                            cordxy(15,8);escribir<<"MOUNTH: ";
				            cordxy(15,reg1);escribir<<mounth.mes<<endl;
			                cordxy(30,8);escribir<<"BASICSALARY: ";
				            cordxy(30,reg1);escribir<<mounth.basicsueld<<endl;
		                    cordxy(45,8);escribir<<"EXPENSES: ";
				            cordxy(45,reg1);escribir<<mounth.expenses<<endl;
				            cordxy(60,8);escribir<<"CASH: ";
				            cordxy(60,reg1);escribir<<mounth.cash<<endl;
				            cordxy(70,8);escribir<<"ACTIVO: ";
				            cordxy(75,reg1);escribir<<mounth.activo<<endl;
				            cod=1;
                            reg++;
                            reg1++;
                            break;
	                   }
		           }
		            if (cod==0){
		               cordxy(12,12);escribir<<" no existe "<<endl;
		               }else {
		               cordxy(6,11);escribir<<" write: "<<endl;
		               cordxy(6,12);escribir<<" 1.for change the codigo: "<<endl;
		   		       cordxy(6,13);escribir<<" 2.for change yours expensess "<<endl;
		   		       cordxy(6,14);escribir<<" 0. para salir:"<<endl;
		               cordxy(21,14);leer>>change;
		        switch (change){
		        	case 1:{
		        		system("cls");
				        system("color c1");
				        cuadropantalla(22,78);
				        cin.ignore(256,'\n');
		        		cordxy(8,13);escribir<<" write your new codigo: "<<endl;
		        		cordxy(9,14);leer.getline(newcodigo,10);
		        		fseek(archivo,ftell(archivo)-sizeof(mounth),SEEK_SET);
	                    fread(&mounth,sizeof(mounth),1,archivo);
                        strcpy(mounth.codigo,newcodigo);
	                    fseek(archivo,ftell(archivo)-sizeof(mounth),SEEK_SET);
                        fwrite(&mounth,sizeof(mounth),1,archivo);			
	                    fclose(archivo);
						break;
					}
					case 2:{
		        		system("cls");
				        system("color c1");
				        cuadropantalla(22,78);
		        		cordxy(8,13);escribir<<" write your news expensess: "<<endl;
		        		cordxy(9,14);leer>>newexpenses;
		        		fseek(archivo,ftell(archivo)-sizeof(mounth),SEEK_SET);
	                    fread(&mounth,sizeof(mounth),1,archivo);
                        mounth.others=newexpenses;
	                    fseek(archivo,ftell(archivo)-sizeof(mounth),SEEK_SET);
                        fwrite(&mounth,sizeof(mounth),1,archivo);			
	                    fclose(archivo);
						break;
					}
					case 0:{
		        		system("cls");
				        system("color c1");
				        cuadropantalla(22,78);
		        		cordxy(8,13);escribir<<" no hubo modificaciones."<<endl;		
	                    fclose(archivo);
						break;
					}
					default :{
						system("cls");
				        system("color c1");
				        cuadropantalla(22,78);
		        		cordxy(8,13);escribir<<" opcion no valida "<<endl;
						break;
					}
				}
			   }		
	        fclose(archivo);
	        system("pause");
			break;
		    }
		    
		    case 4: {
	 	    system("cls");
	 	    system("color 0d");
			cuadropantalla(22,78);
			char google[5];
			char desactivar;
	        cordxy(7,2);escribir<<" write the codigo of registro: "<<endl;
	        cordxy(8,3);leer>>google;
	        archivo=fopen("expenses_mounth.txt", "rb+");
            rewind(archivo);
            int cod=0;
			int reg1=9;
			int reg=1;
			int change=1;
			leer.ignore(256,'\n');
			while(fread(&mounth,sizeof(mounth),1,archivo)){
				if (strcmp(google,mounth.codigo)==0 && mounth.activo=='s' ){
                        mounth.myhome=((mounth.renthome+mounth.serverhome)/3);
	                    mounth.expenses=(mounth.telephone+mounth.myhome+mounth.mysoon+mounth.others+mounth.medplanific+mounth.mefood+mounth.memoum);
	                    mounth.cash=(mounth.basicsueld-mounth.expenses);
                        cordxy(7,8);escribir<<"REG: ";
                        cordxy(7,reg1);escribir<<reg<<endl;
                        cordxy(15,8);escribir<<"MOUNTH: ";
				        cordxy(15,reg1);escribir<<mounth.mes<<endl;
			            cordxy(30,8);escribir<<"BASICSALARY: ";
				        cordxy(30,reg1);escribir<<mounth.basicsueld<<endl;
		                cordxy(45,8);escribir<<"EXPENSES: ";
				        cordxy(45,reg1);escribir<<mounth.expenses<<endl;
				        cordxy(60,8);escribir<<"CASH: ";
				        cordxy(60,reg1);escribir<<mounth.cash<<endl;
				        cordxy(70,8);escribir<<"ACTIVO: ";
				        cordxy(75,reg1);escribir<<mounth.activo<<endl;
				        cod=1;
                        reg++;
                        reg1++;
                        break;
	                   }
		           }
		            if (cod==0){
		               cordxy(12,12);escribir<<" no existe "<<endl;
		               }else {
			     	   cordxy(8,13);escribir<<"si desea desactivarlo escriba n, de lo contrario escriba s: "<<endl;
                       cordxy(9,14);leer>>desactivar;
                       }
				       fseek(archivo,ftell(archivo)-sizeof(mounth),SEEK_SET);
	                   fread(&mounth,sizeof(mounth),1,archivo);
                       mounth.activo=desactivar;
	                   fseek(archivo,ftell(archivo)-sizeof(mounth),SEEK_SET);
                       fwrite(&mounth,sizeof(mounth),1,archivo);			
	        fclose(archivo);
	        system("pause");
				break;
		    }
            case 0:{
            		system("cls");
					cuadropantalla(22,78);
					system("color a0");
					cordxy(8,13);escribir<<" GOD BYE "<<endl;	
			    	break;
			   }
		}
	}

	system("pause");
	return 0;
}
