/************************ main.c ********************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Persona.h"

#define CANTIDAD 300

int main()
{
    char name[51], lastName[51], id[10], isEmpty[10];
    int i, cantidad;

    Persona* array[CANTIDAD];
    FILE * pFile;

    /*
    0X001 0X100 hasta 0X206 0
    0X002 0X500 hasta 0X606 1
    0X003 0X700 hasta 0X806 2
    array == &array[0] == 0X001
    */

    pFile = fopen("data.csv", "r");

    i = 0;

    /* Lee los titulos */
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName,isEmpty);

    while(!feof(pFile)){
        /* Lee los datos */
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, name, lastName,isEmpty);

        array[i] = persona_new();
        persona_setId(array[i], atoi(id)); //atol atof
        persona_setName(array[i],name);
        persona_setLastName(array[i],lastName);

        if(strcmp(isEmpty,"true") == 0)
            persona_setIsEmpty(array[i],1);
        else
            persona_setIsEmpty(array[i],0);

        i++;
    }

    cantidad = i;

    printf("ID\tName\tLast\tName\n");
    for (i=0; i<cantidad; i++)
    {
        if(persona_getIsEmpty(array[i]) == 1)
            printf("%4d\t%-15s\t%15s\n" ,
               persona_getId(array[i]),
               persona_getName(array[i]),
               persona_getLastName(array[i]));
    }

    fclose(pFile);

    return 0;
}

/******************** persona.h *************************/

#ifndef PERSON_H
#define PERSON_H


typedef struct
{
    unsigned int id;
    char name[51];
    char lastName[51];
    char isEmpty;
}Persona;


#endif // PERSON_H

Persona* persona_new();
void persona_delete(Persona* this);
int persona_setId(Persona* this, unsigned int id);
int persona_getId(Persona* this);
int persona_setName(Persona* this, char* name);
char* persona_getName(Persona* this);
int persona_setLastName(Persona* this, char* lastName);
char* persona_getLastName(Persona* this);
int persona_setIsEmpty(Persona* this, unsigned int isEmpty);
int persona_getIsEmpty(Persona* this);

/******************** persona.c *************************/

#include <stdlib.h>
#include <string.h>
#include "Persona.h"

/** \brief
 *
 * \return Persona*
 *
 */
Persona* persona_new()
{
    return malloc(sizeof(Persona));
}

void persona_delete(Persona* this)
{
    free(this);
}

int persona_setId(Persona* this, unsigned int id)
{
    int retorno = -1;
    //validar
    if(this != NULL && id > 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int persona_getId(Persona* this)
{
    int retorno=-1;
    //falta validar
    if(this != NULL)
        retorno = this->id;

    return retorno;
}

int persona_setName(Persona* this, char* name)
{
    int retorno = -1;
    //falta validar
    if(this != NULL && name != NULL)
    {
        strcpy(this->name, name);
        retorno = 0;
    }
    return retorno;
}

char* persona_getName(Persona* this)
{
    char* retorno = NULL;
    //falta validar
    if(this != NULL)
    {
        retorno = this->name;
    }
    return retorno;
}

int persona_setLastName(Persona* this, char* lastName)
{
    int retorno=-1;
    //falta validar
    if(this != NULL && lastName != NULL)
    {
        strcpy(this->lastName,lastName);
        retorno = 0;
    }
    return retorno;
}

char* persona_getLastName(Persona* this)
{
    char* retorno=NULL;
    //falta validar
    if(this != NULL)
    {
        retorno = this->lastName;
    }
    return retorno;
}

int persona_setIsEmpty(Persona* this, unsigned int isEmpty)
{
    int retorno=-1;
    //validar
    if(this != NULL && isEmpty >= 0)
    {
        this->isEmpty = isEmpty;
        retorno = 0;
    }
    return retorno;
}

int persona_getIsEmpty(Persona* this)
{
    int retorno = -1;
    //falta validar
    if(this != NULL)
        retorno = this->isEmpty;

    return retorno;
}

/******************** data.csv *************************/

id,first_name,last_name,is_empty
1,Eric,Knight,false
2,Annie,Castillo,true
3,Johnny,Dunn,false
4,Lawrence,Payne,true
5,Sara,Duncan,true
6,Alan,Webb,true
7,Joan,Payne,false
8,Jason,Perez,false
9,Gary,Sanchez,true
10,Louise,Davis,false
11,Keith,Lynch,false
12,Irene,Cook,false
13,Henry,Jordan,false
14,Albert,Sanchez,false
15,Kathy,Arnold,false
16,Thomas,Hill,false
17,Roy,Gardner,true
18,Patricia,Mason,true
19,Samuel,Chapman,true
20,Phillip,Gardner,true
21,Diana,Young,true
22,Thomas,Burton,false
23,Samuel,Carter,false
24,Annie,Ellis,true
25,Amanda,Myers,false
26,Bonnie,Bailey,true
27,Keith,Hicks,true
28,Scott,Peters,true
29,Henry,Bailey,false
30,Arthur,Gray,false
31,Tammy,Williamson,true
32,Stephen,Hayes,true
33,Betty,Mason,true
34,Robert,Green,true
35,Gregory,Hudson,false
36,Gregory,Hart,true
37,Roger,Matthews,false
38,Billy,Riley,true
39,Evelyn,Rivera,false
40,Gerald,Alvarez,false
41,Judy,Wagner,true
42,Jack,Davis,false
43,Walter,Kelly,true
44,Stephen,George,true
45,Terry,Powell,false
46,Wanda,Johnson,true
47,Brandon,Foster,true
48,Cheryl,Jones,false
49,Louis,Little,false
50,Benjamin,Nguyen,true
51,Brenda,Young,true
52,Bruce,Stewart,false
53,Joan,Price,true
54,Paul,George,true
55,Jeremy,Hicks,true
56,Stephen,Davis,false
57,Joan,Larson,false
58,Gloria,Robinson,true
59,Bonnie,Reynolds,false
60,Keith,Evans,false
61,Carlos,Hall,true
62,Nancy,Burton,false
63,Frank,Webb,true
64,Mildred,Meyer,false
65,Barbara,Gray,true
66,Lawrence,Torres,true
67,Brian,Hicks,true
68,Kelly,Gardner,true
69,Andrew,Hawkins,false
70,Roger,Lane,false
71,Matthew,Campbell,true
72,Melissa,Black,false
73,Todd,Palmer,false
74,Terry,Hansen,false
75,Billy,Collins,false
76,Antonio,Reyes,false
77,Margaret,Wells,false
78,Wayne,Johnston,false
79,Amanda,Lawrence,true
80,Lois,Gordon,false
81,Phyllis,Brooks,false
82,Benjamin,Fox,false
83,Christine,Parker,false
84,Aaron,Ross,true
85,Evelyn,Nelson,false
86,Christopher,Wood,true
87,Marilyn,Rice,true
88,Kevin,Webb,false
89,Antonio,Greene,true
90,Denise,Black,false
91,Sarah,Robertson,false
92,Wayne,Shaw,false
93,Jack,Campbell,false
94,Christina,Bennett,true
95,Janice,Simmons,false
96,Thomas,Warren,true
97,Wayne,Sullivan,false
98,Roger,Washington,true
99,Victor,Carpenter,false
100,Kathryn,Hunter,true
101,Louise,Hernandez,true
102,Martha,Lee,false
103,Steven,Weaver,false
104,Henry,Diaz,false
105,Jason,Chapman,false
106,Elizabeth,Hunt,true
107,Elizabeth,Torres,true
108,Frances,Grant,false
109,Judy,Stanley,true
110,Phyllis,Lawson,false
111,Sandra,Hill,false
112,Heather,Gonzales,false
113,Judy,Burke,true
114,Martha,Rivera,false
115,Carolyn,Gray,false
116,Barbara,Fowler,true
117,Shawn,Kelly,false
118,Kevin,Jordan,true
119,Anthony,Schmidt,false
120,Jeffrey,Richards,false
121,Roy,Lane,true
122,Stephanie,Hayes,false
123,Melissa,Hansen,false
124,Rachel,Hanson,true
125,Jeremy,Spencer,true
126,Christina,Fuller,true
127,Stephen,Mcdonald,true
128,Paul,Richards,false
129,Tammy,Lynch,true
130,Gary,Harrison,false
131,Louis,Edwards,true
132,Antonio,Harrison,true
133,Martha,Hamilton,false
134,Edward,Porter,true
135,Julie,Bailey,false
136,Katherine,King,false
137,Earl,Hansen,true
138,Kimberly,Ferguson,false
139,Andrew,Payne,false
140,Helen,Moore,true
141,Jesse,Ferguson,true
142,Stephanie,Fowler,false
143,James,Taylor,false
144,Roy,Lynch,true
145,Janet,Walker,true
146,Brenda,West,true
147,Nicole,Allen,true
148,Mildred,Mason,false
149,Mark,Lewis,false
150,Irene,Duncan,false
151,Christina,Martinez,true
152,Tammy,Evans,false
153,Joe,Washington,true
154,Lois,Knight,false
155,Edward,Williamson,false
156,Kimberly,Lawrence,false
157,Patrick,Young,true
158,Jean,Vasquez,false
159,Alice,Sanders,true
160,Kathleen,Morales,false
161,Joyce,Mccoy,false
162,Shawn,Chavez,false
163,Joseph,Schmidt,true
164,Robin,Rogers,true
165,Lois,Austin,false
166,Wanda,Gutierrez,true
167,Chris,Collins,true
168,Mary,Hicks,true
169,Timothy,Moore,false
170,Jonathan,Nichols,true
171,Albert,Nelson,false
172,Jane,Hanson,false
173,Tina,Reed,false
174,Elizabeth,Miller,false
175,Patricia,Hamilton,true
176,Peter,Berry,true
177,Stephen,Howard,false
178,Bruce,Burns,false
179,Jose,Murray,false
180,Jimmy,Lynch,false
181,David,Burke,true
182,Stephanie,Gray,false
183,Lois,Rivera,false
184,Christine,Palmer,true
185,Roy,Holmes,false
186,Ronald,Scott,false
187,Andrea,Hunter,false
188,Janice,Dixon,true
189,Beverly,Watkins,false
190,Diane,Knight,true
191,Heather,Cox,true
192,Steve,Ryan,false
193,Lillian,Boyd,false
194,Roy,Myers,true
195,Brandon,Moreno,true
196,Roger,Arnold,false
197,Harry,Allen,true
198,Janet,Pierce,false
199,Douglas,Lee,true
200,Michelle,James,true
201,Patricia,Hanson,true
202,Mildred,Henderson,false
203,Jacqueline,Chavez,true
204,Patrick,Jones,true
205,Angela,Rose,false
206,Marilyn,Meyer,false
207,Michelle,Dunn,true
208,Charles,Mills,false
209,Benjamin,Howard,false
210,Heather,Campbell,false
211,Evelyn,Vasquez,false
212,Nicole,Perkins,false
213,William,Tucker,true
214,Todd,Kennedy,true
215,Deborah,Smith,false
216,Justin,Simpson,false
217,Sara,Lawrence,false
218,Cheryl,Jacobs,true
219,Gloria,Richards,true
220,Emily,Edwards,false
221,Brandon,Howard,true
222,Shirley,Freeman,false
223,Adam,Nichols,false
224,Kathy,Butler,true
225,Lisa,Andrews,false
226,Arthur,Hunter,false
227,Nicholas,Price,true
228,Elizabeth,Wagner,true
229,George,Barnes,true
230,Barbara,Welch,false
231,Walter,Rodriguez,true
232,George,Harper,false
233,Jacqueline,Jacobs,false
234,James,Cruz,true
235,Douglas,Stephens,true
236,Evelyn,Bradley,false
237,Walter,Anderson,true
238,Shirley,Perkins,false
239,Carlos,Patterson,true
240,Bruce,Clark,true
241,Diane,Stewart,true
242,Willie,Patterson,false
243,Phyllis,Hudson,true
244,Eugene,Gibson,true
245,Carolyn,Powell,true
246,Jack,Fox,true
247,Shirley,Cruz,true
248,Phyllis,Fowler,true
249,Marilyn,Burton,false
250,Dorothy,Garrett,true
251,Donna,Armstrong,false
252,Aaron,Smith,false
253,Kevin,Snyder,false
254,Teresa,Reyes,false
255,Cheryl,Sullivan,true
256,Dorothy,Ford,false
257,Raymond,Boyd,true
258,Helen,Mendoza,false
259,Virginia,Oliver,true
260,Andrew,Wells,true
261,Wayne,Bailey,false
262,Jerry,Wheeler,true
263,Carl,Cook,true
264,Maria,Dixon,false
265,Brian,Andrews,true
266,Roy,Diaz,true
267,Larry,Alexander,true
268,Douglas,Armstrong,true
269,Michael,Graham,false
270,Randy,George,true
271,Donald,Bryant,false
272,Kelly,Jenkins,true
273,Judith,Jordan,false
274,Julie,Lopez,false
275,Martha,Dean,true
276,David,Kelley,false
277,Nicholas,Clark,false
278,Jimmy,Matthews,true
279,Kathleen,Hall,false
280,Linda,Arnold,false
281,Nicole,Austin,false
282,Ryan,Hudson,true
283,Judy,Williamson,true
284,Carol,Fox,true
285,Emily,Young,false
286,Beverly,Hughes,true
287,Joyce,Grant,true
288,Jean,Richardson,true
289,Juan,Harper,true
290,Sara,Williams,false
291,Anna,Grant,false
292,Doris,Carr,false
293,Albert,Frazier,false
294,Joan,Morgan,false
295,Carl,Snyder,true
296,Susan,George,false
297,Rebecca,Woods,false
298,Frank,Castillo,true
299,Billy,Gonzalez,true
300,Kenneth,Brooks,true


