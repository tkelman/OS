/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ATTRIBUTETEXT = 258,
     ELEMENTTEXT = 259,
     INTEGER = 260,
     DOUBLE = 261,
     QUOTE = 262,
     GREATERTHAN = 263,
     ENDOFELEMENT = 264,
     OSOLSTART = 265,
     OSOLATTRIBUTETEXT = 266,
     OSOLEND = 267,
     LOCATIONTYPEATT = 268,
     TRANSPORTTYPEATT = 269,
     NUMBEROFOTHEROPTIONSATT = 270,
     NUMBEROFJOBIDSATT = 271,
     NUMBEROFPATHSATT = 272,
     NUMBEROFPATHPAIRSATT = 273,
     FROMATT = 274,
     TOATT = 275,
     MAKECOPYATT = 276,
     SOLVERATT = 277,
     CATEGORYATT = 278,
     TYPEATT = 279,
     GROUPWEIGHTATT = 280,
     NUMBEROFPROCESSESATT = 281,
     NUMBEROFSOLVEROPTIONSATT = 282,
     NUMBEROFSOSATT = 283,
     NUMBEROFVARIABLESATT = 284,
     NUMBEROFOBJECTIVESATT = 285,
     NUMBEROFCONSTRAINTSATT = 286,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 287,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 288,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 289,
     NUMBEROFVARATT = 290,
     NUMBEROFOBJATT = 291,
     NUMBEROFCONATT = 292,
     NAMEATT = 293,
     IDXATT = 294,
     SOSIDXATT = 295,
     VALUEATT = 296,
     UNITATT = 297,
     DESCRIPTIONATT = 298,
     LBVALUEATT = 299,
     UBVALUEATT = 300,
     GENERALSTART = 301,
     GENERALEND = 302,
     SYSTEMSTART = 303,
     SYSTEMEND = 304,
     SERVICESTART = 305,
     SERVICEEND = 306,
     JOBSTART = 307,
     JOBEND = 308,
     OPTIMIZATIONSTART = 309,
     OPTIMIZATIONEND = 310,
     SERVICEURISTART = 311,
     SERVICEURIEND = 312,
     SERVICENAMESTART = 313,
     SERVICENAMEEND = 314,
     INSTANCENAMESTART = 315,
     INSTANCENAMEEND = 316,
     INSTANCELOCATIONSTART = 317,
     INSTANCELOCATIONEND = 318,
     JOBIDSTART = 319,
     JOBIDEND = 320,
     SOLVERTOINVOKESTART = 321,
     SOLVERTOINVOKEEND = 322,
     LICENSESTART = 323,
     LICENSEEND = 324,
     USERNAMESTART = 325,
     USERNAMEEND = 326,
     PASSWORDSTART = 327,
     PASSWORDEND = 328,
     CONTACTSTART = 329,
     CONTACTEND = 330,
     OTHEROPTIONSSTART = 331,
     OTHEROPTIONSEND = 332,
     OTHERSTART = 333,
     OTHEREND = 334,
     MINDISKSPACESTART = 335,
     MINDISKSPACEEND = 336,
     MINMEMORYSIZESTART = 337,
     MINMEMORYSIZEEND = 338,
     MINCPUSPEEDSTART = 339,
     MINCPUSPEEDEND = 340,
     MINCPUNUMBERSTART = 341,
     MINCPUNUMBEREND = 342,
     SERVICETYPESTART = 343,
     SERVICETYPEEND = 344,
     MAXTIMESTART = 345,
     MAXTIMEEND = 346,
     SCHEDULEDSTARTTIMESTART = 347,
     SCHEDULEDSTARTTIMEEND = 348,
     DEPENDENCIESSTART = 349,
     DEPENDENCIESEND = 350,
     REQUIREDDIRECTORIESSTART = 351,
     REQUIREDDIRECTORIESEND = 352,
     REQUIREDFILESSTART = 353,
     REQUIREDFILESEND = 354,
     PATHSTART = 355,
     PATHEND = 356,
     PATHPAIRSTART = 357,
     PATHPAIREND = 358,
     DIRECTORIESTOMAKESTART = 359,
     DIRECTORIESTOMAKEEND = 360,
     FILESTOMAKESTART = 361,
     FILESTOMAKEEND = 362,
     DIRECTORIESTODELETESTART = 363,
     DIRECTORIESTODELETEEND = 364,
     FILESTODELETESTART = 365,
     FILESTODELETEEND = 366,
     INPUTDIRECTORIESTOMOVESTART = 367,
     INPUTDIRECTORIESTOMOVEEND = 368,
     INPUTFILESTOMOVESTART = 369,
     INPUTFILESTOMOVEEND = 370,
     OUTPUTDIRECTORIESTOMOVESTART = 371,
     OUTPUTDIRECTORIESTOMOVEEND = 372,
     OUTPUTFILESTOMOVESTART = 373,
     OUTPUTFILESTOMOVEEND = 374,
     PROCESSESTOKILLSTART = 375,
     PROCESSESTOKILLEND = 376,
     PROCESSSTART = 377,
     PROCESSEND = 378,
     VARIABLESSTART = 379,
     VARIABLESEND = 380,
     INITIALVARIABLEVALUESSTART = 381,
     INITIALVARIABLEVALUESEND = 382,
     VARSTART = 383,
     VAREND = 384,
     INITIALVARIABLEVALUESSTRINGSTART = 385,
     INITIALVARIABLEVALUESSTRINGEND = 386,
     INITIALBASISSTATUSSTART = 387,
     INITIALBASISSTATUSEND = 388,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 389,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 390,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 391,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 392,
     SOSSTART = 393,
     SOSEND = 394,
     OBJECTIVESSTART = 395,
     OBJECTIVESEND = 396,
     INITIALOBJECTIVEVALUESSTART = 397,
     INITIALOBJECTIVEVALUESEND = 398,
     OBJSTART = 399,
     OBJEND = 400,
     INITIALOBJECTIVEBOUNDSSTART = 401,
     INITIALOBJECTIVEBOUNDSEND = 402,
     CONSTRAINTSSTART = 403,
     CONSTRAINTSEND = 404,
     INITIALCONSTRAINTVALUESSTART = 405,
     INITIALCONSTRAINTVALUESEND = 406,
     CONSTART = 407,
     CONEND = 408,
     INITIALDUALVALUESSTART = 409,
     INITIALDUALVALUESEND = 410,
     SOLVEROPTIONSSTART = 411,
     SOLVEROPTIONSEND = 412,
     SOLVEROPTIONSTART = 413,
     SOLVEROPTIONEND = 414,
     DUMMY = 415
   };
#endif
/* Tokens.  */
#define ATTRIBUTETEXT 258
#define ELEMENTTEXT 259
#define INTEGER 260
#define DOUBLE 261
#define QUOTE 262
#define GREATERTHAN 263
#define ENDOFELEMENT 264
#define OSOLSTART 265
#define OSOLATTRIBUTETEXT 266
#define OSOLEND 267
#define LOCATIONTYPEATT 268
#define TRANSPORTTYPEATT 269
#define NUMBEROFOTHEROPTIONSATT 270
#define NUMBEROFJOBIDSATT 271
#define NUMBEROFPATHSATT 272
#define NUMBEROFPATHPAIRSATT 273
#define FROMATT 274
#define TOATT 275
#define MAKECOPYATT 276
#define SOLVERATT 277
#define CATEGORYATT 278
#define TYPEATT 279
#define GROUPWEIGHTATT 280
#define NUMBEROFPROCESSESATT 281
#define NUMBEROFSOLVEROPTIONSATT 282
#define NUMBEROFSOSATT 283
#define NUMBEROFVARIABLESATT 284
#define NUMBEROFOBJECTIVESATT 285
#define NUMBEROFCONSTRAINTSATT 286
#define NUMBEROFOTHERVARIABLEOPTIONSATT 287
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 288
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 289
#define NUMBEROFVARATT 290
#define NUMBEROFOBJATT 291
#define NUMBEROFCONATT 292
#define NAMEATT 293
#define IDXATT 294
#define SOSIDXATT 295
#define VALUEATT 296
#define UNITATT 297
#define DESCRIPTIONATT 298
#define LBVALUEATT 299
#define UBVALUEATT 300
#define GENERALSTART 301
#define GENERALEND 302
#define SYSTEMSTART 303
#define SYSTEMEND 304
#define SERVICESTART 305
#define SERVICEEND 306
#define JOBSTART 307
#define JOBEND 308
#define OPTIMIZATIONSTART 309
#define OPTIMIZATIONEND 310
#define SERVICEURISTART 311
#define SERVICEURIEND 312
#define SERVICENAMESTART 313
#define SERVICENAMEEND 314
#define INSTANCENAMESTART 315
#define INSTANCENAMEEND 316
#define INSTANCELOCATIONSTART 317
#define INSTANCELOCATIONEND 318
#define JOBIDSTART 319
#define JOBIDEND 320
#define SOLVERTOINVOKESTART 321
#define SOLVERTOINVOKEEND 322
#define LICENSESTART 323
#define LICENSEEND 324
#define USERNAMESTART 325
#define USERNAMEEND 326
#define PASSWORDSTART 327
#define PASSWORDEND 328
#define CONTACTSTART 329
#define CONTACTEND 330
#define OTHEROPTIONSSTART 331
#define OTHEROPTIONSEND 332
#define OTHERSTART 333
#define OTHEREND 334
#define MINDISKSPACESTART 335
#define MINDISKSPACEEND 336
#define MINMEMORYSIZESTART 337
#define MINMEMORYSIZEEND 338
#define MINCPUSPEEDSTART 339
#define MINCPUSPEEDEND 340
#define MINCPUNUMBERSTART 341
#define MINCPUNUMBEREND 342
#define SERVICETYPESTART 343
#define SERVICETYPEEND 344
#define MAXTIMESTART 345
#define MAXTIMEEND 346
#define SCHEDULEDSTARTTIMESTART 347
#define SCHEDULEDSTARTTIMEEND 348
#define DEPENDENCIESSTART 349
#define DEPENDENCIESEND 350
#define REQUIREDDIRECTORIESSTART 351
#define REQUIREDDIRECTORIESEND 352
#define REQUIREDFILESSTART 353
#define REQUIREDFILESEND 354
#define PATHSTART 355
#define PATHEND 356
#define PATHPAIRSTART 357
#define PATHPAIREND 358
#define DIRECTORIESTOMAKESTART 359
#define DIRECTORIESTOMAKEEND 360
#define FILESTOMAKESTART 361
#define FILESTOMAKEEND 362
#define DIRECTORIESTODELETESTART 363
#define DIRECTORIESTODELETEEND 364
#define FILESTODELETESTART 365
#define FILESTODELETEEND 366
#define INPUTDIRECTORIESTOMOVESTART 367
#define INPUTDIRECTORIESTOMOVEEND 368
#define INPUTFILESTOMOVESTART 369
#define INPUTFILESTOMOVEEND 370
#define OUTPUTDIRECTORIESTOMOVESTART 371
#define OUTPUTDIRECTORIESTOMOVEEND 372
#define OUTPUTFILESTOMOVESTART 373
#define OUTPUTFILESTOMOVEEND 374
#define PROCESSESTOKILLSTART 375
#define PROCESSESTOKILLEND 376
#define PROCESSSTART 377
#define PROCESSEND 378
#define VARIABLESSTART 379
#define VARIABLESEND 380
#define INITIALVARIABLEVALUESSTART 381
#define INITIALVARIABLEVALUESEND 382
#define VARSTART 383
#define VAREND 384
#define INITIALVARIABLEVALUESSTRINGSTART 385
#define INITIALVARIABLEVALUESSTRINGEND 386
#define INITIALBASISSTATUSSTART 387
#define INITIALBASISSTATUSEND 388
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 389
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 390
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 391
#define SOSVARIABLEBRANCHINGWEIGHTSEND 392
#define SOSSTART 393
#define SOSEND 394
#define OBJECTIVESSTART 395
#define OBJECTIVESEND 396
#define INITIALOBJECTIVEVALUESSTART 397
#define INITIALOBJECTIVEVALUESEND 398
#define OBJSTART 399
#define OBJEND 400
#define INITIALOBJECTIVEBOUNDSSTART 401
#define INITIALOBJECTIVEBOUNDSEND 402
#define CONSTRAINTSSTART 403
#define CONSTRAINTSEND 404
#define INITIALCONSTRAINTVALUESSTART 405
#define INITIALCONSTRAINTVALUESEND 406
#define CONSTART 407
#define CONEND 408
#define INITIALDUALVALUESSTART 409
#define INITIALDUALVALUESEND 410
#define SOLVEROPTIONSSTART 411
#define SOLVEROPTIONSEND 412
#define SOLVEROPTIONSTART 413
#define SOLVEROPTIONEND 414
#define DUMMY 415




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
	double dval;
	int ival;
	char* sval;
}
/* Line 1529 of yacc.c.  */

	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

