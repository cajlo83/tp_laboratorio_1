#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    char nombre[31];
    char division;
}eAlumno;


eAlumno * New_Alumno();
eAlumno * New_Alumno_Parametros(char* nombre, char division);
void Alumno_Delete(eAlumno* this);
int getNombre(eAlumno* this,char* nombre);
int getDivision(eAlumno* this,char* division);
int setNombre(eAlumno* this,char* nombre);
int setDivision(eAlumno* this,char division);
void PrintAlumno(eAlumno* this);
int ParsearAlumnoTexto(FILE* pArchivo);
int ParsearAlumnoBinario(FILE* pArchivo);

int main()
{
	eAlumno alumno;

	return 0;
}


void PrintAlumno(eAlumno* this)
{
	char nombre[31];
	char division;

	if(
	getNombre(this,nombre) &&
	getDivision(this,&division)
	)
	{
		printf("\nNombre: %c\nDivisión: ",nombre,division);
	}

}

int setNombre(eAlumno* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL)
	{
		retorno = 1;
		strcpy(this->nombre,nombre);
	}

	return retorno;
}


int setDivision(eAlumno* this,char division)
{
	int retorno = 0;

	if(this != NULL)
	{
		retorno = 1;
		this->division = division;
	}

	return retorno;
}


int getNombre(eAlumno* this,char* nombre)
{
	int retorno = 0;

	if(this != NULL)
	{
		retorno = 1;
		strcpy(nombre,this->nombre);
	}

	return retorno;
}


int getDivision(eAlumno* this,char* division)
{
	int retorno = 0;

	if(this != NULL)
	{
		retorno = 1;
		*division = this->division;
	}

	return retorno;
}


eAlumno * New_Alumno()
{
	eAlumno * this;

	if(this != NULL)
	{
		this = (eAlumno*) malloc(sizeof(eAlumno));

		this->division = 32;
		strcpy(this->nombre,"");
	}

	return this;
}

eAlumno * New_Alumno_Parametros(char* nombre, char* division)
{
	eAlumno* this;
	this = New_Alumno();


	if
	(this == NULL || ((setNombre(this,nombre) == 0 ||
	setDivision(this,division) == 0)))
	{
		Alumno_Delete(this);
		this = NULL;
	}

	return this;
}

void Alumno_Delete(eAlumno* this)
{
	if(this != NULL)
	{
		free(this);
	}
}


int ParsearAlumnoTexto(FILE* pArchivo)
{
	eAlumno alumnoAux;

	char nombreAux[31];
	char division;

    int retorno = 0;

    if(pArchivo != NULL)
    {
        while(!feof(pArchivo))
        {

            if(fscanf(pArchivo, "%[^,],%[^\n]\n", nombreAux, division) == 2)
            {
                alumnoAux = New_Alumno_Parametros(nombreAux,division);

                if(alumnoAux != NULL)
                {
                	//Agregar a lista dinámica
                    retorno = 1;
                }
            }
        }
    }
    return retorno;
}



int ParsearAlumnoBinario(FILE* pArchivo)
{
    eAlumno* alumno;
    int retorno = 0;

    if(pArchivo != NULL)
    {
        while(!feof(pArchivo))
        {
        	alumno = New_alumno();
            fread(alumno,sizeof(eAlumno),1,pArchivo);
        	//Agregar a lista dinámica
        }
        retorno = 1;
    }
    return retorno;
}

