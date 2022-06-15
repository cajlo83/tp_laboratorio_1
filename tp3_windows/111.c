//funcion(void)
//{
//	FILE *listaPasajeros_bin;
//	struct a pers;
//	int cant;
//	if ((listaPasajeros_bin=fopen("databin.dat","rb"))==NULL)
//	{
//		printf("No se pudo abrir el archivo");
//		exit(1);
//	}
//	while(!feof(listaPasajeros_bin))
//	{
//		cant=fread(&pers,sizeof(pers),1,listaPasajeros_bin);
//		if(cant!=1)
//		{
//			if(feof(listaPasajeros_bin))
//			{
//				break;
//			}
//			else
//			{
//				error("No leyo el ultimo registro");
//				break;
//			}
//		}
//		printf("\n%s\t%d",pers.nombre,pers.edad);
//	}
//	fclose(listaPasajeros_bin);
//	getch();
//}
