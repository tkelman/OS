
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse         osolparse
#define yylex           osollex
#define yyerror         osolerror
#define yylval          osollval
#define yychar          osolchar
#define yydebug         osoldebug
#define yynerrs         osolnerrs
#define yylloc          osollloc

/* Copy the first part of user declarations.  */




#include "OSConfig.h"
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSGeneral.h"
#include "OSErrorClass.h"
#include "OSOption.h"
#include "OSoLParserData.h"
#include "OSgLParserData.h"
#include "OSnLParserData.h"
#include "OSBase64.h"

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>

//#define DEBUG

#ifdef DEBUG
#define YYDEBUG 1
#endif

typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osol_scan_string (const char *yy_str , void* yyscanner  );
int osollex_init(void** ptr_yy_globals);
int osollex_destroy (void* yyscanner );
int osolget_lineno( void* yyscanner);
char *osolget_text (void* yyscanner );
void osolset_lineno (int line_number , void* yyscanner );
void osolset_extra (OSoLParserData* parserData , void* yyscanner );
void  yygetOSOption(const char *ch, OSOption* m_osoption, OSoLParserData *m_parserData, OSgLParserData *osglData, OSnLParserData *osnlData ) throw(ErrorClass);
void osol_empty_vectors( OSoLParserData* parserData);
void osgl_empty_vectors( OSgLParserData* osglData);
void osnl_empty_vectors( OSnLParserData* osnlData);





/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ATTRIBUTETEXT = 258,
     ELEMENTTEXT = 259,
     ITEMTEXT = 260,
     INTEGER = 261,
     DOUBLE = 262,
     QUOTE = 263,
     TWOQUOTES = 264,
     GREATERTHAN = 265,
     ENDOFELEMENT = 266,
     OSOLSTART = 267,
     OSOLSTARTEMPTY = 268,
     OSOLATTRIBUTETEXT = 269,
     OSOLEND = 270,
     NUMBEROFOTHEROPTIONSATT = 271,
     NUMBEROFENUMERATIONSATT = 272,
     NUMBEROFJOBIDSATT = 273,
     NUMBEROFPATHSATT = 274,
     NUMBEROFPATHPAIRSATT = 275,
     FROMATT = 276,
     TOATT = 277,
     MAKECOPYATT = 278,
     CATEGORYATT = 279,
     TYPEATT = 280,
     GROUPWEIGHTATT = 281,
     NUMBEROFPROCESSESATT = 282,
     NUMBEROFSOLVEROPTIONSATT = 283,
     NUMBEROFSOSATT = 284,
     NUMBEROFVARIABLESATT = 285,
     NUMBEROFOBJECTIVESATT = 286,
     NUMBEROFCONSTRAINTSATT = 287,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 288,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 289,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 290,
     NUMBEROFITEMSATT = 291,
     NUMBEROFVARATT = 292,
     NUMBEROFOBJATT = 293,
     NUMBEROFCONATT = 294,
     NUMBEROFELATT = 295,
     NAMEATT = 296,
     IDXATT = 297,
     SOSIDXATT = 298,
     VALUEATT = 299,
     UNITATT = 300,
     DESCRIPTIONATT = 301,
     CONTYPEATT = 302,
     EMPTYCONTYPEATT = 303,
     ENUMTYPEATT = 304,
     EMPTYENUMTYPEATT = 305,
     OBJTYPEATT = 306,
     EMPTYOBJTYPEATT = 307,
     VARTYPEATT = 308,
     EMPTYVARTYPEATT = 309,
     EMPTYTYPEATT = 310,
     EMPTYNAMEATT = 311,
     EMPTYCATEGORYATT = 312,
     EMPTYDESCRIPTIONATT = 313,
     EMPTYUNITATT = 314,
     EMPTYVALUEATT = 315,
     EMPTYLBVALUEATT = 316,
     EMPTYUBVALUEATT = 317,
     LBVALUEATT = 318,
     UBVALUEATT = 319,
     EMPTYLBDUALVALUEATT = 320,
     EMPTYUBDUALVALUEATT = 321,
     LBDUALVALUEATT = 322,
     UBDUALVALUEATT = 323,
     SOLVERATT = 324,
     EMPTYSOLVERATT = 325,
     WEIGHTATT = 326,
     EMPTYWEIGHTATT = 327,
     TRANSPORTTYPEATT = 328,
     LOCATIONTYPEATT = 329,
     GENERALSTART = 330,
     GENERALEND = 331,
     SYSTEMSTART = 332,
     SYSTEMEND = 333,
     SERVICESTART = 334,
     SERVICEEND = 335,
     JOBSTART = 336,
     JOBEND = 337,
     OPTIMIZATIONSTART = 338,
     OPTIMIZATIONEND = 339,
     SERVICEURISTART = 340,
     SERVICEURIEND = 341,
     SERVICENAMESTART = 342,
     SERVICENAMEEND = 343,
     INSTANCENAMESTART = 344,
     INSTANCENAMEEND = 345,
     INSTANCELOCATIONSTART = 346,
     INSTANCELOCATIONEND = 347,
     JOBIDSTART = 348,
     JOBIDEND = 349,
     SOLVERTOINVOKESTART = 350,
     SOLVERTOINVOKEEND = 351,
     LICENSESTART = 352,
     LICENSEEND = 353,
     USERNAMESTART = 354,
     USERNAMEEND = 355,
     PASSWORDSTART = 356,
     PASSWORDEND = 357,
     CONTACTSTART = 358,
     CONTACTEND = 359,
     OTHEROPTIONSSTART = 360,
     OTHEROPTIONSEND = 361,
     OTHERSTART = 362,
     OTHEREND = 363,
     MINDISKSPACESTART = 364,
     MINDISKSPACEEND = 365,
     MINMEMORYSTART = 366,
     MINMEMORYEND = 367,
     MINCPUSPEEDSTART = 368,
     MINCPUSPEEDEND = 369,
     MINCPUNUMBERSTART = 370,
     MINCPUNUMBEREND = 371,
     SERVICETYPESTART = 372,
     SERVICETYPEEND = 373,
     MAXTIMESTART = 374,
     MAXTIMEEND = 375,
     REQUESTEDSTARTTIMESTART = 376,
     REQUESTEDSTARTTIMEEND = 377,
     DEPENDENCIESSTART = 378,
     DEPENDENCIESEND = 379,
     REQUIREDDIRECTORIESSTART = 380,
     REQUIREDDIRECTORIESEND = 381,
     REQUIREDFILESSTART = 382,
     REQUIREDFILESEND = 383,
     PATHSTART = 384,
     PATHEND = 385,
     PATHPAIRSTART = 386,
     PATHPAIREND = 387,
     DIRECTORIESTOMAKESTART = 388,
     DIRECTORIESTOMAKEEND = 389,
     FILESTOMAKESTART = 390,
     FILESTOMAKEEND = 391,
     DIRECTORIESTODELETESTART = 392,
     DIRECTORIESTODELETEEND = 393,
     FILESTODELETESTART = 394,
     FILESTODELETEEND = 395,
     INPUTDIRECTORIESTOMOVESTART = 396,
     INPUTDIRECTORIESTOMOVEEND = 397,
     INPUTFILESTOMOVESTART = 398,
     INPUTFILESTOMOVEEND = 399,
     OUTPUTDIRECTORIESTOMOVESTART = 400,
     OUTPUTDIRECTORIESTOMOVEEND = 401,
     OUTPUTFILESTOMOVESTART = 402,
     OUTPUTFILESTOMOVEEND = 403,
     PROCESSESTOKILLSTART = 404,
     PROCESSESTOKILLEND = 405,
     PROCESSSTART = 406,
     PROCESSEND = 407,
     VARIABLESSTART = 408,
     VARIABLESEND = 409,
     INITIALVARIABLEVALUESSTART = 410,
     INITIALVARIABLEVALUESEND = 411,
     VARSTART = 412,
     VAREND = 413,
     INITIALVARIABLEVALUESSTRINGSTART = 414,
     INITIALVARIABLEVALUESSTRINGEND = 415,
     INITIALBASISSTATUSSTART = 416,
     INITIALBASISSTATUSEND = 417,
     BASICSTART = 418,
     BASICEND = 419,
     ATUPPERSTART = 420,
     ATUPPEREND = 421,
     ATLOWERSTART = 422,
     ATLOWEREND = 423,
     ATEQUALITYSTART = 424,
     ATEQUALITYEND = 425,
     SUPERBASICSTART = 426,
     SUPERBASICEND = 427,
     ISFREESTART = 428,
     ISFREEEND = 429,
     UNKNOWNSTART = 430,
     UNKNOWNEND = 431,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 432,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 433,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 434,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 435,
     SOSSTART = 436,
     SOSEND = 437,
     OBJECTIVESSTART = 438,
     OBJECTIVESEND = 439,
     INITIALOBJECTIVEVALUESSTART = 440,
     INITIALOBJECTIVEVALUESEND = 441,
     OBJSTART = 442,
     OBJEND = 443,
     INITIALOBJECTIVEBOUNDSSTART = 444,
     INITIALOBJECTIVEBOUNDSEND = 445,
     CONSTRAINTSSTART = 446,
     CONSTRAINTSEND = 447,
     INITIALCONSTRAINTVALUESSTART = 448,
     INITIALCONSTRAINTVALUESEND = 449,
     CONSTART = 450,
     CONEND = 451,
     INITIALDUALVALUESSTART = 452,
     INITIALDUALVALUESEND = 453,
     SOLVEROPTIONSSTART = 454,
     SOLVEROPTIONSEND = 455,
     SOLVEROPTIONSTART = 456,
     SOLVEROPTIONEND = 457,
     ENUMERATIONSTART = 458,
     ENUMERATIONEND = 459,
     ITEMEMPTY = 460,
     ITEMSTART = 461,
     ITEMEND = 462,
     ITEMSTARTANDEND = 463,
     BASE64START = 464,
     BASE64END = 465,
     INCRATT = 466,
     MULTATT = 467,
     SIZEOFATT = 468,
     ELSTART = 469,
     ELEND = 470,
     HEADERSTART = 471,
     HEADEREND = 472,
     FILENAMESTART = 473,
     FILENAMEEND = 474,
     FILENAMEEMPTY = 475,
     FILENAMESTARTANDEND = 476,
     FILESOURCESTART = 477,
     FILESOURCEEND = 478,
     FILESOURCEEMPTY = 479,
     FILESOURCESTARTANDEND = 480,
     FILEDESCRIPTIONSTART = 481,
     FILEDESCRIPTIONEND = 482,
     FILEDESCRIPTIONEMPTY = 483,
     FILEDESCRIPTIONSTARTANDEND = 484,
     FILECREATORSTART = 485,
     FILECREATOREND = 486,
     FILECREATOREMPTY = 487,
     FILECREATORSTARTANDEND = 488,
     FILELICENCESTART = 489,
     FILELICENCEEND = 490,
     FILELICENCEEMPTY = 491,
     FILELICENCESTARTANDEND = 492,
     MATRIXSTART = 493,
     MATRIXEND = 494,
     BASEMATRIXEND = 495,
     BASEMATRIXSTART = 496,
     BLOCKSTART = 497,
     BLOCKEND = 498,
     BLOCKSSTART = 499,
     BLOCKSEND = 500,
     EMPTYSYMMETRYATT = 501,
     SYMMETRYATT = 502,
     EMPTYEXCLUDEATT = 503,
     EXCLUDEATT = 504,
     CONSTANTATT = 505,
     NUMBEROFBLOCKSATT = 506,
     NUMBEROFCOLUMNSATT = 507,
     NUMBEROFROWSATT = 508,
     NUMBEROFVARIDXATT = 509,
     BASEMATRIXIDXATT = 510,
     TARGETMATRIXFIRSTROWATT = 511,
     TARGETMATRIXFIRSTCOLATT = 512,
     BASEMATRIXSTARTROWATT = 513,
     BASEMATRIXSTARTCOLATT = 514,
     BASEMATRIXENDROWATT = 515,
     BASEMATRIXENDCOLATT = 516,
     SCALARMULTIPLIERATT = 517,
     EMPTYBASETRANSPOSEATT = 518,
     BASETRANSPOSEATT = 519,
     ELEMENTSSTART = 520,
     ELEMENTSEND = 521,
     CONSTANTELEMENTSSTART = 522,
     CONSTANTELEMENTSEND = 523,
     STARTVECTORSTART = 524,
     STARTVECTOREND = 525,
     NONZEROSSTART = 526,
     NONZEROSEND = 527,
     INDEXESSTART = 528,
     INDEXESEND = 529,
     VALUESSTART = 530,
     VALUESEND = 531,
     VARREFERENCEELEMENTSSTART = 532,
     VARREFERENCEELEMENTSEND = 533,
     LINEARELEMENTSSTART = 534,
     LINEARELEMENTSEND = 535,
     GENERALELEMENTSSTART = 536,
     GENERALELEMENTSEND = 537,
     CONREFERENCEELEMENTSSTART = 538,
     CONREFERENCEELEMENTSEND = 539,
     OBJREFERENCEELEMENTSSTART = 540,
     OBJREFERENCEELEMENTSEND = 541,
     PATTERNELEMENTSSTART = 542,
     PATTERNELEMENTSEND = 543,
     VARIDXSTART = 544,
     VARIDXEND = 545,
     TRANSFORMATIONSTART = 546,
     TRANSFORMATIONEND = 547,
     COLOFFSETSSTART = 548,
     COLOFFSETSEND = 549,
     ROWOFFSETSSTART = 550,
     ROWOFFSETSEND = 551,
     EMPTYROWMAJORATT = 552,
     ROWMAJORATT = 553,
     BLOCKROWIDXATT = 554,
     BLOCKCOLIDXATT = 555,
     DUMMY = 556,
     NONLINEAREXPRESSIONSSTART = 557,
     NONLINEAREXPRESSIONSEND = 558,
     NUMBEROFNONLINEAREXPRESSIONS = 559,
     NLSTART = 560,
     NLEND = 561,
     POWERSTART = 562,
     POWEREND = 563,
     PLUSSTART = 564,
     PLUSEND = 565,
     MINUSSTART = 566,
     MINUSEND = 567,
     DIVIDESTART = 568,
     DIVIDEEND = 569,
     LNSTART = 570,
     LNEND = 571,
     SQRTSTART = 572,
     SQRTEND = 573,
     SUMSTART = 574,
     SUMEND = 575,
     PRODUCTSTART = 576,
     PRODUCTEND = 577,
     EXPSTART = 578,
     EXPEND = 579,
     NEGATESTART = 580,
     NEGATEEND = 581,
     IFSTART = 582,
     IFEND = 583,
     SQUARESTART = 584,
     SQUAREEND = 585,
     COSSTART = 586,
     COSEND = 587,
     SINSTART = 588,
     SINEND = 589,
     VARIABLESTART = 590,
     VARIABLEEND = 591,
     ABSSTART = 592,
     ABSEND = 593,
     ERFSTART = 594,
     ERFEND = 595,
     MAXSTART = 596,
     MAXEND = 597,
     ALLDIFFSTART = 598,
     ALLDIFFEND = 599,
     MINSTART = 600,
     MINEND = 601,
     ESTART = 602,
     EEND = 603,
     PISTART = 604,
     PIEND = 605,
     TIMESSTART = 606,
     TIMESEND = 607,
     NUMBERSTART = 608,
     NUMBEREND = 609,
     MATRIXTRACESTART = 610,
     MATRIXTRACEEND = 611,
     MATRIXTOSCALARSTART = 612,
     MATRIXTOSCALAREND = 613,
     IDATT = 614,
     COEFATT = 615
   };
#endif
/* Tokens.  */
#define ATTRIBUTETEXT 258
#define ELEMENTTEXT 259
#define ITEMTEXT 260
#define INTEGER 261
#define DOUBLE 262
#define QUOTE 263
#define TWOQUOTES 264
#define GREATERTHAN 265
#define ENDOFELEMENT 266
#define OSOLSTART 267
#define OSOLSTARTEMPTY 268
#define OSOLATTRIBUTETEXT 269
#define OSOLEND 270
#define NUMBEROFOTHEROPTIONSATT 271
#define NUMBEROFENUMERATIONSATT 272
#define NUMBEROFJOBIDSATT 273
#define NUMBEROFPATHSATT 274
#define NUMBEROFPATHPAIRSATT 275
#define FROMATT 276
#define TOATT 277
#define MAKECOPYATT 278
#define CATEGORYATT 279
#define TYPEATT 280
#define GROUPWEIGHTATT 281
#define NUMBEROFPROCESSESATT 282
#define NUMBEROFSOLVEROPTIONSATT 283
#define NUMBEROFSOSATT 284
#define NUMBEROFVARIABLESATT 285
#define NUMBEROFOBJECTIVESATT 286
#define NUMBEROFCONSTRAINTSATT 287
#define NUMBEROFOTHERVARIABLEOPTIONSATT 288
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 289
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 290
#define NUMBEROFITEMSATT 291
#define NUMBEROFVARATT 292
#define NUMBEROFOBJATT 293
#define NUMBEROFCONATT 294
#define NUMBEROFELATT 295
#define NAMEATT 296
#define IDXATT 297
#define SOSIDXATT 298
#define VALUEATT 299
#define UNITATT 300
#define DESCRIPTIONATT 301
#define CONTYPEATT 302
#define EMPTYCONTYPEATT 303
#define ENUMTYPEATT 304
#define EMPTYENUMTYPEATT 305
#define OBJTYPEATT 306
#define EMPTYOBJTYPEATT 307
#define VARTYPEATT 308
#define EMPTYVARTYPEATT 309
#define EMPTYTYPEATT 310
#define EMPTYNAMEATT 311
#define EMPTYCATEGORYATT 312
#define EMPTYDESCRIPTIONATT 313
#define EMPTYUNITATT 314
#define EMPTYVALUEATT 315
#define EMPTYLBVALUEATT 316
#define EMPTYUBVALUEATT 317
#define LBVALUEATT 318
#define UBVALUEATT 319
#define EMPTYLBDUALVALUEATT 320
#define EMPTYUBDUALVALUEATT 321
#define LBDUALVALUEATT 322
#define UBDUALVALUEATT 323
#define SOLVERATT 324
#define EMPTYSOLVERATT 325
#define WEIGHTATT 326
#define EMPTYWEIGHTATT 327
#define TRANSPORTTYPEATT 328
#define LOCATIONTYPEATT 329
#define GENERALSTART 330
#define GENERALEND 331
#define SYSTEMSTART 332
#define SYSTEMEND 333
#define SERVICESTART 334
#define SERVICEEND 335
#define JOBSTART 336
#define JOBEND 337
#define OPTIMIZATIONSTART 338
#define OPTIMIZATIONEND 339
#define SERVICEURISTART 340
#define SERVICEURIEND 341
#define SERVICENAMESTART 342
#define SERVICENAMEEND 343
#define INSTANCENAMESTART 344
#define INSTANCENAMEEND 345
#define INSTANCELOCATIONSTART 346
#define INSTANCELOCATIONEND 347
#define JOBIDSTART 348
#define JOBIDEND 349
#define SOLVERTOINVOKESTART 350
#define SOLVERTOINVOKEEND 351
#define LICENSESTART 352
#define LICENSEEND 353
#define USERNAMESTART 354
#define USERNAMEEND 355
#define PASSWORDSTART 356
#define PASSWORDEND 357
#define CONTACTSTART 358
#define CONTACTEND 359
#define OTHEROPTIONSSTART 360
#define OTHEROPTIONSEND 361
#define OTHERSTART 362
#define OTHEREND 363
#define MINDISKSPACESTART 364
#define MINDISKSPACEEND 365
#define MINMEMORYSTART 366
#define MINMEMORYEND 367
#define MINCPUSPEEDSTART 368
#define MINCPUSPEEDEND 369
#define MINCPUNUMBERSTART 370
#define MINCPUNUMBEREND 371
#define SERVICETYPESTART 372
#define SERVICETYPEEND 373
#define MAXTIMESTART 374
#define MAXTIMEEND 375
#define REQUESTEDSTARTTIMESTART 376
#define REQUESTEDSTARTTIMEEND 377
#define DEPENDENCIESSTART 378
#define DEPENDENCIESEND 379
#define REQUIREDDIRECTORIESSTART 380
#define REQUIREDDIRECTORIESEND 381
#define REQUIREDFILESSTART 382
#define REQUIREDFILESEND 383
#define PATHSTART 384
#define PATHEND 385
#define PATHPAIRSTART 386
#define PATHPAIREND 387
#define DIRECTORIESTOMAKESTART 388
#define DIRECTORIESTOMAKEEND 389
#define FILESTOMAKESTART 390
#define FILESTOMAKEEND 391
#define DIRECTORIESTODELETESTART 392
#define DIRECTORIESTODELETEEND 393
#define FILESTODELETESTART 394
#define FILESTODELETEEND 395
#define INPUTDIRECTORIESTOMOVESTART 396
#define INPUTDIRECTORIESTOMOVEEND 397
#define INPUTFILESTOMOVESTART 398
#define INPUTFILESTOMOVEEND 399
#define OUTPUTDIRECTORIESTOMOVESTART 400
#define OUTPUTDIRECTORIESTOMOVEEND 401
#define OUTPUTFILESTOMOVESTART 402
#define OUTPUTFILESTOMOVEEND 403
#define PROCESSESTOKILLSTART 404
#define PROCESSESTOKILLEND 405
#define PROCESSSTART 406
#define PROCESSEND 407
#define VARIABLESSTART 408
#define VARIABLESEND 409
#define INITIALVARIABLEVALUESSTART 410
#define INITIALVARIABLEVALUESEND 411
#define VARSTART 412
#define VAREND 413
#define INITIALVARIABLEVALUESSTRINGSTART 414
#define INITIALVARIABLEVALUESSTRINGEND 415
#define INITIALBASISSTATUSSTART 416
#define INITIALBASISSTATUSEND 417
#define BASICSTART 418
#define BASICEND 419
#define ATUPPERSTART 420
#define ATUPPEREND 421
#define ATLOWERSTART 422
#define ATLOWEREND 423
#define ATEQUALITYSTART 424
#define ATEQUALITYEND 425
#define SUPERBASICSTART 426
#define SUPERBASICEND 427
#define ISFREESTART 428
#define ISFREEEND 429
#define UNKNOWNSTART 430
#define UNKNOWNEND 431
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 432
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 433
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 434
#define SOSVARIABLEBRANCHINGWEIGHTSEND 435
#define SOSSTART 436
#define SOSEND 437
#define OBJECTIVESSTART 438
#define OBJECTIVESEND 439
#define INITIALOBJECTIVEVALUESSTART 440
#define INITIALOBJECTIVEVALUESEND 441
#define OBJSTART 442
#define OBJEND 443
#define INITIALOBJECTIVEBOUNDSSTART 444
#define INITIALOBJECTIVEBOUNDSEND 445
#define CONSTRAINTSSTART 446
#define CONSTRAINTSEND 447
#define INITIALCONSTRAINTVALUESSTART 448
#define INITIALCONSTRAINTVALUESEND 449
#define CONSTART 450
#define CONEND 451
#define INITIALDUALVALUESSTART 452
#define INITIALDUALVALUESEND 453
#define SOLVEROPTIONSSTART 454
#define SOLVEROPTIONSEND 455
#define SOLVEROPTIONSTART 456
#define SOLVEROPTIONEND 457
#define ENUMERATIONSTART 458
#define ENUMERATIONEND 459
#define ITEMEMPTY 460
#define ITEMSTART 461
#define ITEMEND 462
#define ITEMSTARTANDEND 463
#define BASE64START 464
#define BASE64END 465
#define INCRATT 466
#define MULTATT 467
#define SIZEOFATT 468
#define ELSTART 469
#define ELEND 470
#define HEADERSTART 471
#define HEADEREND 472
#define FILENAMESTART 473
#define FILENAMEEND 474
#define FILENAMEEMPTY 475
#define FILENAMESTARTANDEND 476
#define FILESOURCESTART 477
#define FILESOURCEEND 478
#define FILESOURCEEMPTY 479
#define FILESOURCESTARTANDEND 480
#define FILEDESCRIPTIONSTART 481
#define FILEDESCRIPTIONEND 482
#define FILEDESCRIPTIONEMPTY 483
#define FILEDESCRIPTIONSTARTANDEND 484
#define FILECREATORSTART 485
#define FILECREATOREND 486
#define FILECREATOREMPTY 487
#define FILECREATORSTARTANDEND 488
#define FILELICENCESTART 489
#define FILELICENCEEND 490
#define FILELICENCEEMPTY 491
#define FILELICENCESTARTANDEND 492
#define MATRIXSTART 493
#define MATRIXEND 494
#define BASEMATRIXEND 495
#define BASEMATRIXSTART 496
#define BLOCKSTART 497
#define BLOCKEND 498
#define BLOCKSSTART 499
#define BLOCKSEND 500
#define EMPTYSYMMETRYATT 501
#define SYMMETRYATT 502
#define EMPTYEXCLUDEATT 503
#define EXCLUDEATT 504
#define CONSTANTATT 505
#define NUMBEROFBLOCKSATT 506
#define NUMBEROFCOLUMNSATT 507
#define NUMBEROFROWSATT 508
#define NUMBEROFVARIDXATT 509
#define BASEMATRIXIDXATT 510
#define TARGETMATRIXFIRSTROWATT 511
#define TARGETMATRIXFIRSTCOLATT 512
#define BASEMATRIXSTARTROWATT 513
#define BASEMATRIXSTARTCOLATT 514
#define BASEMATRIXENDROWATT 515
#define BASEMATRIXENDCOLATT 516
#define SCALARMULTIPLIERATT 517
#define EMPTYBASETRANSPOSEATT 518
#define BASETRANSPOSEATT 519
#define ELEMENTSSTART 520
#define ELEMENTSEND 521
#define CONSTANTELEMENTSSTART 522
#define CONSTANTELEMENTSEND 523
#define STARTVECTORSTART 524
#define STARTVECTOREND 525
#define NONZEROSSTART 526
#define NONZEROSEND 527
#define INDEXESSTART 528
#define INDEXESEND 529
#define VALUESSTART 530
#define VALUESEND 531
#define VARREFERENCEELEMENTSSTART 532
#define VARREFERENCEELEMENTSEND 533
#define LINEARELEMENTSSTART 534
#define LINEARELEMENTSEND 535
#define GENERALELEMENTSSTART 536
#define GENERALELEMENTSEND 537
#define CONREFERENCEELEMENTSSTART 538
#define CONREFERENCEELEMENTSEND 539
#define OBJREFERENCEELEMENTSSTART 540
#define OBJREFERENCEELEMENTSEND 541
#define PATTERNELEMENTSSTART 542
#define PATTERNELEMENTSEND 543
#define VARIDXSTART 544
#define VARIDXEND 545
#define TRANSFORMATIONSTART 546
#define TRANSFORMATIONEND 547
#define COLOFFSETSSTART 548
#define COLOFFSETSEND 549
#define ROWOFFSETSSTART 550
#define ROWOFFSETSEND 551
#define EMPTYROWMAJORATT 552
#define ROWMAJORATT 553
#define BLOCKROWIDXATT 554
#define BLOCKCOLIDXATT 555
#define DUMMY 556
#define NONLINEAREXPRESSIONSSTART 557
#define NONLINEAREXPRESSIONSEND 558
#define NUMBEROFNONLINEAREXPRESSIONS 559
#define NLSTART 560
#define NLEND 561
#define POWERSTART 562
#define POWEREND 563
#define PLUSSTART 564
#define PLUSEND 565
#define MINUSSTART 566
#define MINUSEND 567
#define DIVIDESTART 568
#define DIVIDEEND 569
#define LNSTART 570
#define LNEND 571
#define SQRTSTART 572
#define SQRTEND 573
#define SUMSTART 574
#define SUMEND 575
#define PRODUCTSTART 576
#define PRODUCTEND 577
#define EXPSTART 578
#define EXPEND 579
#define NEGATESTART 580
#define NEGATEEND 581
#define IFSTART 582
#define IFEND 583
#define SQUARESTART 584
#define SQUAREEND 585
#define COSSTART 586
#define COSEND 587
#define SINSTART 588
#define SINEND 589
#define VARIABLESTART 590
#define VARIABLEEND 591
#define ABSSTART 592
#define ABSEND 593
#define ERFSTART 594
#define ERFEND 595
#define MAXSTART 596
#define MAXEND 597
#define ALLDIFFSTART 598
#define ALLDIFFEND 599
#define MINSTART 600
#define MINEND 601
#define ESTART 602
#define EEND 603
#define PISTART 604
#define PIEND 605
#define TIMESSTART 606
#define TIMESEND 607
#define NUMBERSTART 608
#define NUMBEREND 609
#define MATRIXTRACESTART 610
#define MATRIXTRACEEND 611
#define MATRIXTOSCALARSTART 612
#define MATRIXTOSCALAREND 613
#define IDATT 614
#define COEFATT 615




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


    double dval;
    int ival;
    char* sval;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
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


/* Copy the second part of user declarations.  */



std::string addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData* osnlData, std::string errormsg ) ;
void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData* osnlData, std::string errormsg );
int osollex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);
#define scanner parserData->scanner



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  365
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  831
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1246
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1696

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   615

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   362,
     364,     2,     2,   363,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   361,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    13,    15,    16,    18,    20,
      22,    24,    28,    30,    32,    33,    40,    41,    43,    44,
      47,    49,    51,    53,    56,    58,    62,    64,    66,    69,
      71,    73,    75,    77,    79,    81,    83,    85,    87,    89,
      91,    94,    96,    98,   100,   103,   105,   109,   111,   114,
     116,   118,   120,   123,   125,   129,   131,   134,   136,   138,
     140,   143,   145,   149,   151,   155,   157,   158,   160,   164,
     166,   168,   171,   173,   177,   179,   182,   184,   186,   188,
     191,   193,   197,   199,   202,   204,   206,   208,   211,   213,
     217,   219,   222,   224,   226,   228,   231,   233,   237,   239,
     242,   244,   246,   248,   251,   253,   257,   259,   262,   264,
     266,   268,   271,   273,   277,   279,   283,   285,   286,   288,
     292,   294,   296,   299,   301,   305,   307,   311,   313,   315,
     317,   319,   322,   324,   328,   330,   332,   335,   339,   341,
     343,   344,   347,   349,   351,   353,   356,   358,   359,   362,
     364,   366,   368,   371,   373,   377,   379,   381,   384,   386,
     388,   390,   392,   394,   398,   400,   402,   403,   406,   408,
     410,   414,   416,   420,   422,   424,   425,   428,   430,   432,
     436,   438,   442,   444,   446,   447,   450,   452,   454,   458,
     460,   464,   466,   467,   469,   473,   475,   479,   481,   483,
     485,   487,   490,   492,   496,   498,   500,   503,   507,   509,
     511,   512,   515,   517,   519,   521,   524,   526,   527,   530,
     532,   534,   536,   539,   541,   545,   547,   549,   552,   554,
     556,   559,   561,   563,   565,   568,   570,   574,   576,   580,
     582,   584,   586,   588,   591,   593,   597,   599,   601,   604,
     608,   610,   612,   613,   616,   618,   620,   622,   625,   627,
     628,   631,   633,   635,   637,   640,   642,   646,   648,   650,
     653,   655,   657,   659,   661,   663,   665,   667,   669,   671,
     673,   675,   677,   679,   681,   683,   687,   689,   690,   692,
     694,   696,   699,   701,   705,   707,   709,   712,   714,   716,
     718,   721,   723,   727,   729,   733,   735,   737,   739,   741,
     744,   746,   750,   752,   755,   760,   764,   766,   768,   770,
     773,   775,   779,   783,   785,   787,   789,   792,   794,   798,
     802,   804,   806,   808,   811,   813,   817,   821,   823,   825,
     827,   830,   832,   836,   840,   842,   844,   846,   848,   851,
     853,   857,   859,   862,   864,   868,   870,   872,   874,   876,
     879,   881,   885,   887,   890,   892,   896,   898,   900,   902,
     904,   907,   909,   913,   915,   918,   920,   924,   926,   928,
     930,   932,   935,   937,   941,   943,   946,   948,   952,   954,
     956,   958,   960,   963,   965,   969,   973,   975,   977,   979,
     981,   984,   986,   990,   994,   996,   998,  1000,  1002,  1005,
    1007,  1011,  1013,  1016,  1021,  1025,  1027,  1029,  1031,  1033,
    1036,  1038,  1042,  1044,  1046,  1049,  1053,  1055,  1057,  1058,
    1061,  1063,  1065,  1067,  1070,  1072,  1073,  1077,  1079,  1081,
    1082,  1085,  1087,  1089,  1091,  1093,  1095,  1097,  1101,  1106,
    1107,  1111,  1113,  1115,  1116,  1118,  1120,  1122,  1124,  1128,
    1135,  1136,  1140,  1142,  1144,  1146,  1148,  1151,  1153,  1157,
    1159,  1161,  1164,  1168,  1170,  1172,  1173,  1176,  1178,  1180,
    1182,  1185,  1187,  1188,  1192,  1194,  1196,  1198,  1200,  1203,
    1205,  1209,  1211,  1213,  1216,  1220,  1222,  1224,  1225,  1228,
    1230,  1232,  1234,  1237,  1239,  1240,  1243,  1245,  1247,  1249,
    1251,  1255,  1263,  1264,  1268,  1270,  1272,  1274,  1276,  1278,
    1282,  1284,  1285,  1289,  1291,  1293,  1295,  1297,  1299,  1303,
    1305,  1306,  1310,  1312,  1314,  1316,  1318,  1320,  1324,  1326,
    1327,  1331,  1333,  1335,  1337,  1339,  1341,  1345,  1347,  1348,
    1352,  1354,  1356,  1358,  1360,  1362,  1366,  1368,  1369,  1373,
    1375,  1377,  1379,  1381,  1383,  1387,  1389,  1390,  1394,  1396,
    1398,  1400,  1402,  1404,  1408,  1410,  1411,  1415,  1417,  1419,
    1421,  1423,  1426,  1428,  1432,  1434,  1436,  1439,  1443,  1445,
    1447,  1448,  1451,  1453,  1455,  1457,  1460,  1462,  1463,  1467,
    1469,  1474,  1476,  1478,  1481,  1483,  1487,  1489,  1492,  1496,
    1498,  1500,  1501,  1504,  1506,  1508,  1510,  1512,  1514,  1517,
    1519,  1523,  1524,  1527,  1531,  1533,  1535,  1536,  1539,  1541,
    1543,  1545,  1547,  1549,  1551,  1553,  1555,  1557,  1559,  1561,
    1563,  1566,  1568,  1572,  1574,  1576,  1578,  1581,  1585,  1587,
    1589,  1590,  1593,  1595,  1597,  1599,  1601,  1603,  1605,  1608,
    1610,  1611,  1615,  1617,  1619,  1620,  1622,  1624,  1626,  1628,
    1632,  1637,  1638,  1642,  1644,  1646,  1648,  1650,  1653,  1655,
    1659,  1661,  1663,  1666,  1670,  1672,  1674,  1675,  1678,  1680,
    1682,  1684,  1687,  1689,  1690,  1694,  1696,  1698,  1700,  1702,
    1705,  1707,  1711,  1713,  1715,  1718,  1722,  1724,  1726,  1727,
    1730,  1732,  1734,  1736,  1738,  1741,  1743,  1744,  1747,  1749,
    1751,  1753,  1755,  1759,  1767,  1768,  1772,  1774,  1776,  1778,
    1780,  1782,  1786,  1788,  1789,  1793,  1795,  1797,  1799,  1801,
    1803,  1807,  1809,  1810,  1814,  1816,  1818,  1820,  1822,  1824,
    1828,  1830,  1831,  1835,  1837,  1839,  1841,  1843,  1845,  1849,
    1851,  1852,  1856,  1858,  1860,  1862,  1864,  1866,  1870,  1872,
    1873,  1877,  1879,  1881,  1883,  1885,  1887,  1891,  1893,  1894,
    1898,  1900,  1902,  1904,  1906,  1908,  1912,  1914,  1915,  1918,
    1922,  1924,  1926,  1927,  1930,  1932,  1934,  1936,  1938,  1940,
    1942,  1944,  1946,  1948,  1950,  1952,  1954,  1957,  1959,  1963,
    1965,  1967,  1969,  1972,  1976,  1978,  1980,  1981,  1984,  1986,
    1988,  1990,  1992,  1994,  1996,  1999,  2001,  2002,  2006,  2008,
    2010,  2011,  2013,  2015,  2017,  2019,  2023,  2028,  2029,  2033,
    2035,  2037,  2039,  2041,  2044,  2046,  2050,  2052,  2054,  2057,
    2061,  2063,  2065,  2066,  2069,  2071,  2073,  2075,  2078,  2080,
    2081,  2085,  2087,  2089,  2091,  2093,  2096,  2098,  2102,  2104,
    2106,  2109,  2113,  2115,  2117,  2118,  2121,  2123,  2125,  2127,
    2129,  2132,  2134,  2135,  2138,  2140,  2142,  2144,  2146,  2150,
    2158,  2159,  2163,  2165,  2167,  2169,  2171,  2173,  2177,  2179,
    2180,  2184,  2186,  2188,  2190,  2192,  2194,  2198,  2200,  2201,
    2205,  2207,  2209,  2211,  2213,  2215,  2219,  2221,  2222,  2226,
    2228,  2230,  2232,  2234,  2236,  2240,  2242,  2243,  2247,  2249,
    2251,  2253,  2255,  2257,  2261,  2263,  2264,  2268,  2270,  2272,
    2274,  2276,  2278,  2282,  2284,  2285,  2289,  2291,  2293,  2295,
    2297,  2299,  2303,  2305,  2306,  2309,  2313,  2315,  2317,  2318,
    2321,  2323,  2325,  2327,  2329,  2331,  2333,  2335,  2337,  2339,
    2341,  2343,  2345,  2348,  2350,  2354,  2356,  2358,  2360,  2363,
    2367,  2369,  2371,  2372,  2375,  2377,  2379,  2381,  2383,  2385,
    2387,  2390,  2392,  2393,  2397,  2399,  2401,  2403,  2405,  2407,
    2411,  2412,  2415,  2419,  2421,  2423,  2425,  2428,  2430,  2432,
    2434,  2436,  2438,  2440,  2442,  2444,  2446,  2449,  2451,  2455,
    2457,  2459,  2462,  2464,  2466,  2468,  2470,  2472,  2476,  2478,
    2480,  2483,  2488,  2492,  2494,  2496,  2497,  2500,  2502,  2504,
    2506,  2510,  2514,  2518,  2521,  2523,  2525,  2527,  2529,  2531,
    2535,  2537,  2539,  2541,  2543,  2547,  2549,  2551,  2553,  2555,
    2559,  2561,  2563,  2565,  2567,  2571,  2573,  2578,  2580,  2582,
    2587,  2589,  2591,  2593,  2595,  2599,  2601,  2603,  2605,  2607,
    2612,  2614,  2616,  2618,  2620,  2624,  2626,  2628,  2630,  2632,
    2636,  2638,  2640,  2642,  2644,  2648,  2650,  2652,  2657,  2659,
    2661,  2663,  2665,  2669,  2671,  2673,  2675,  2677,  2681,  2683,
    2685,  2687,  2689,  2694,  2696,  2698,  2700,  2702,  2706,  2708,
    2710,  2712,  2714,  2718,  2720,  2722,  2724,  2726,  2730,  2735,
    2740,  2745,  2750,  2755,  2760,  2765,  2770,  2775,  2780,  2785,
    2790,  2795,  2800,  2805,  2810,  2815,  2820,  2822,  2825,  2829,
    2831,  2833,  2834,  2837,  2839,  2841,  2843,  2845,  2847,  2849,
    2853,  2855,  2857,  2859,  2862,  2863,  2866,  2868,  2870,  2872,
    2874,  2877,  2879,  2881,  2883,  2886,  2888,  2892,  2894,  2896,
    2899,  2901,  2903,  2905,  2907,  2909,  2910,  2912,  2914,  2916,
    2918,  2920,  2924,  2925,  2927,  2929,  2931,  2933,  2935,  2939,
    2940,  2942,  2944,  2946,  2948,  2950,  2954,  2955,  2957,  2959,
    2961,  2963,  2965,  2969,  2970,  2972,  2974,  2976,  2978,  2980,
    2984,  2986,  2988,  2989,  2992,  2996,  2998,  3000,  3001,  3004,
    3006,  3008,  3012,  3016,  3021,  3023,  3025,  3028,  3030,  3034,
    3039,  3044,  3049,  3051,  3053,  3056,  3058
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     366,     0,    -1,   367,   375,   373,    -1,   368,   369,   370,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   371,    -1,
     372,    -1,    11,    -1,    10,   375,   373,    -1,   374,    -1,
      15,    -1,    -1,   376,   377,   463,   511,   539,   655,    -1,
      -1,  1153,    -1,    -1,   378,   379,    -1,    75,    -1,   380,
      -1,   381,    -1,    10,    76,    -1,    11,    -1,    10,   382,
      76,    -1,   383,    -1,   384,    -1,   383,   384,    -1,   385,
      -1,   391,    -1,   397,    -1,   403,    -1,   411,    -1,   417,
      -1,   423,    -1,   429,    -1,   435,    -1,   441,    -1,   449,
      -1,   386,   387,    -1,    85,    -1,   388,    -1,   389,    -1,
      10,    86,    -1,    11,    -1,    10,   390,    86,    -1,     4,
      -1,   392,   393,    -1,    87,    -1,   394,    -1,   395,    -1,
      10,    88,    -1,    11,    -1,    10,   396,    88,    -1,     4,
      -1,   398,   399,    -1,    89,    -1,   400,    -1,   401,    -1,
      10,    90,    -1,    11,    -1,    10,   402,    90,    -1,     4,
      -1,   404,   405,   407,    -1,    91,    -1,    -1,   406,    -1,
      74,     3,     8,    -1,   408,    -1,   409,    -1,    10,    92,
      -1,    11,    -1,    10,   410,    92,    -1,     4,    -1,   412,
     413,    -1,    93,    -1,   414,    -1,   415,    -1,    10,    94,
      -1,    11,    -1,    10,   416,    94,    -1,     4,    -1,   418,
     419,    -1,    95,    -1,   420,    -1,   421,    -1,    10,    96,
      -1,    11,    -1,    10,   422,    96,    -1,     4,    -1,   424,
     425,    -1,    97,    -1,   426,    -1,   427,    -1,    10,    98,
      -1,    11,    -1,    10,   428,    98,    -1,     4,    -1,   430,
     431,    -1,    99,    -1,   432,    -1,   433,    -1,    10,   100,
      -1,    11,    -1,    10,   434,   100,    -1,     4,    -1,   436,
     437,    -1,   101,    -1,   438,    -1,   439,    -1,    10,   102,
      -1,    11,    -1,    10,   440,   102,    -1,     4,    -1,   442,
     443,   445,    -1,   103,    -1,    -1,   444,    -1,    73,     3,
       8,    -1,   446,    -1,   447,    -1,    10,   104,    -1,    11,
      -1,    10,   448,   104,    -1,     4,    -1,   450,   451,   452,
      -1,   105,    -1,  1131,    -1,   453,    -1,   454,    -1,    10,
     106,    -1,    11,    -1,    10,   455,   106,    -1,   456,    -1,
     457,    -1,   456,   457,    -1,   458,   459,   462,    -1,   107,
      -1,   460,    -1,    -1,   460,   461,    -1,  1082,    -1,  1113,
      -1,  1061,    -1,    10,   108,    -1,    11,    -1,    -1,   464,
     465,    -1,    77,    -1,   466,    -1,   467,    -1,    10,    78,
      -1,    11,    -1,    10,   468,    78,    -1,   469,    -1,   470,
      -1,   469,   470,    -1,   471,    -1,   478,    -1,   485,    -1,
     492,    -1,   497,    -1,   472,   473,   476,    -1,   109,    -1,
     474,    -1,    -1,   474,   475,    -1,  1109,    -1,  1061,    -1,
      10,   477,   110,    -1,  1149,    -1,   479,   480,   483,    -1,
     111,    -1,   481,    -1,    -1,   481,   482,    -1,  1109,    -1,
    1061,    -1,    10,   484,   112,    -1,  1149,    -1,   486,   487,
     490,    -1,   113,    -1,   488,    -1,    -1,   488,   489,    -1,
    1109,    -1,  1061,    -1,    10,   491,   114,    -1,  1149,    -1,
     493,   494,   495,    -1,   115,    -1,    -1,  1061,    -1,    10,
     496,   116,    -1,     6,    -1,   498,   499,   500,    -1,   105,
      -1,  1131,    -1,   501,    -1,   502,    -1,    10,   106,    -1,
      11,    -1,    10,   503,   106,    -1,   504,    -1,   505,    -1,
     504,   505,    -1,   506,   507,   510,    -1,   107,    -1,   508,
      -1,    -1,   508,   509,    -1,  1082,    -1,  1113,    -1,  1061,
      -1,    10,   108,    -1,    11,    -1,    -1,   512,   513,    -1,
      79,    -1,   514,    -1,   515,    -1,    10,    80,    -1,    11,
      -1,    10,   516,    80,    -1,   517,    -1,   518,    -1,   517,
     518,    -1,   519,    -1,   525,    -1,   520,   521,    -1,   117,
      -1,   522,    -1,   523,    -1,    10,   118,    -1,    11,    -1,
      10,   524,   118,    -1,     4,    -1,   526,   527,   528,    -1,
     105,    -1,  1131,    -1,   529,    -1,   530,    -1,    10,   106,
      -1,    11,    -1,    10,   531,   106,    -1,   532,    -1,   533,
      -1,   532,   533,    -1,   534,   535,   538,    -1,   107,    -1,
     536,    -1,    -1,   536,   537,    -1,  1082,    -1,  1113,    -1,
    1061,    -1,    10,   108,    -1,    11,    -1,    -1,   540,   541,
      -1,    81,    -1,   542,    -1,   543,    -1,    10,    82,    -1,
      11,    -1,    10,   544,    82,    -1,   545,    -1,   546,    -1,
     545,   546,    -1,   547,    -1,   555,    -1,   561,    -1,   569,
      -1,   574,    -1,   579,    -1,   584,    -1,   589,    -1,   597,
      -1,   613,    -1,   605,    -1,   621,    -1,   627,    -1,   633,
      -1,   641,    -1,   548,   549,   550,    -1,   119,    -1,    -1,
    1109,    -1,   551,    -1,   552,    -1,    10,   120,    -1,    11,
      -1,    10,   553,   120,    -1,   554,    -1,  1149,    -1,   556,
     557,    -1,   121,    -1,   558,    -1,   559,    -1,    10,   122,
      -1,    11,    -1,    10,   560,   122,    -1,     4,    -1,   562,
     563,   564,    -1,   123,    -1,  1126,    -1,   565,    -1,   566,
      -1,    10,   124,    -1,    11,    -1,    10,   567,   124,    -1,
     568,    -1,   567,   568,    -1,    93,    10,     4,    94,    -1,
     570,  1134,   571,    -1,   125,    -1,   572,    -1,   573,    -1,
      10,   126,    -1,    11,    -1,    10,  1042,   126,    -1,   575,
    1134,   576,    -1,   127,    -1,   577,    -1,   578,    -1,    10,
     128,    -1,    11,    -1,    10,  1042,   128,    -1,   580,  1134,
     581,    -1,   133,    -1,   582,    -1,   583,    -1,    10,   134,
      -1,    11,    -1,    10,  1042,   134,    -1,   585,  1134,   586,
      -1,   135,    -1,   587,    -1,   588,    -1,    10,   136,    -1,
      11,    -1,    10,  1042,   136,    -1,   590,   591,   592,    -1,
     141,    -1,  1133,    -1,   593,    -1,   594,    -1,    10,   142,
      -1,    11,    -1,    10,   595,   142,    -1,   596,    -1,   595,
     596,    -1,  1044,    -1,   598,   599,   600,    -1,   143,    -1,
    1133,    -1,   601,    -1,   602,    -1,    10,   144,    -1,    11,
      -1,    10,   603,   144,    -1,   604,    -1,   603,   604,    -1,
    1044,    -1,   606,   607,   608,    -1,   147,    -1,  1133,    -1,
     609,    -1,   610,    -1,    10,   148,    -1,    11,    -1,    10,
     611,   148,    -1,   612,    -1,   611,   612,    -1,  1044,    -1,
     614,   615,   616,    -1,   145,    -1,  1133,    -1,   617,    -1,
     618,    -1,    10,   146,    -1,    11,    -1,    10,   619,   146,
      -1,   620,    -1,   619,   620,    -1,  1044,    -1,   622,   623,
     624,    -1,   139,    -1,  1134,    -1,   625,    -1,   626,    -1,
      10,   140,    -1,    11,    -1,    10,  1042,   140,    -1,   628,
     629,   630,    -1,   137,    -1,  1134,    -1,   631,    -1,   632,
      -1,    10,   138,    -1,    11,    -1,    10,  1042,   138,    -1,
     634,   635,   636,    -1,   149,    -1,  1135,    -1,   637,    -1,
     638,    -1,    10,   150,    -1,    11,    -1,    10,   639,   150,
      -1,   640,    -1,   639,   640,    -1,   151,    10,     4,   152,
      -1,   642,   643,   644,    -1,   105,    -1,  1131,    -1,   645,
      -1,   646,    -1,    10,   106,    -1,    11,    -1,    10,   647,
     106,    -1,   648,    -1,   649,    -1,   648,   649,    -1,   650,
     651,   654,    -1,   107,    -1,   652,    -1,    -1,   652,   653,
      -1,  1082,    -1,  1113,    -1,  1061,    -1,    10,   108,    -1,
      11,    -1,    -1,   656,   657,   660,    -1,    83,    -1,   658,
      -1,    -1,   658,   659,    -1,  1138,    -1,  1122,    -1,  1128,
      -1,   661,    -1,   662,    -1,    11,    -1,    10,   663,    84,
      -1,   664,   802,   911,  1020,    -1,    -1,   665,   666,   668,
      -1,   153,    -1,   667,    -1,    -1,  1132,    -1,   669,    -1,
     670,    -1,    11,    -1,    10,   671,   154,    -1,   672,   686,
     700,   755,   769,   784,    -1,    -1,   673,   674,   675,    -1,
     155,    -1,  1137,    -1,   676,    -1,   677,    -1,    10,   156,
      -1,    11,    -1,    10,   678,   156,    -1,   679,    -1,   680,
      -1,   679,   680,    -1,   681,   682,   685,    -1,   157,    -1,
     683,    -1,    -1,   683,   684,    -1,  1071,    -1,  1082,    -1,
    1113,    -1,    10,   158,    -1,    11,    -1,    -1,   687,   688,
     689,    -1,   159,    -1,  1137,    -1,   690,    -1,   691,    -1,
      10,   160,    -1,    11,    -1,    10,   692,   160,    -1,   693,
      -1,   694,    -1,   693,   694,    -1,   695,   696,   699,    -1,
     157,    -1,   697,    -1,    -1,   697,   698,    -1,  1071,    -1,
    1082,    -1,  1113,    -1,    10,   158,    -1,    11,    -1,    -1,
     701,   702,    -1,   161,    -1,   703,    -1,   704,    -1,    11,
      -1,    10,   705,   162,    -1,   706,   713,   720,   727,   734,
     741,   748,    -1,    -1,   707,   708,   709,    -1,   163,    -1,
    1123,    -1,   710,    -1,   711,    -1,    11,    -1,    10,   712,
     164,    -1,  1181,    -1,    -1,   714,   715,   716,    -1,   167,
      -1,  1123,    -1,   717,    -1,   718,    -1,    11,    -1,    10,
     719,   168,    -1,  1181,    -1,    -1,   721,   722,   723,    -1,
     165,    -1,  1123,    -1,   724,    -1,   725,    -1,    11,    -1,
      10,   726,   166,    -1,  1181,    -1,    -1,   728,   729,   730,
      -1,   169,    -1,  1123,    -1,   731,    -1,   732,    -1,    11,
      -1,    10,   733,   170,    -1,  1181,    -1,    -1,   735,   736,
     737,    -1,   173,    -1,  1123,    -1,   738,    -1,   739,    -1,
      11,    -1,    10,   740,   174,    -1,  1181,    -1,    -1,   742,
     743,   744,    -1,   171,    -1,  1123,    -1,   745,    -1,   746,
      -1,    11,    -1,    10,   747,   172,    -1,  1181,    -1,    -1,
     749,   750,   751,    -1,   175,    -1,  1123,    -1,   752,    -1,
     753,    -1,    11,    -1,    10,   754,   176,    -1,  1181,    -1,
      -1,   756,   757,   758,    -1,   177,    -1,  1137,    -1,   759,
      -1,   760,    -1,    10,   178,    -1,    11,    -1,    10,   761,
     178,    -1,   762,    -1,   763,    -1,   762,   763,    -1,   764,
     765,   768,    -1,   157,    -1,   766,    -1,    -1,   766,   767,
      -1,  1071,    -1,  1082,    -1,  1113,    -1,    10,   158,    -1,
      11,    -1,    -1,   770,   771,   772,    -1,   179,    -1,    29,
       8,     6,     8,    -1,   773,    -1,   774,    -1,    10,   180,
      -1,    11,    -1,    10,   775,   180,    -1,   776,    -1,   775,
     776,    -1,   777,   778,   781,    -1,   181,    -1,   779,    -1,
      -1,   779,   780,    -1,  1094,    -1,  1137,    -1,  1069,    -1,
     782,    -1,   783,    -1,    10,   182,    -1,    11,    -1,    10,
     762,   182,    -1,    -1,   784,   785,    -1,   786,   787,   790,
      -1,   107,    -1,   788,    -1,    -1,   788,   789,    -1,  1137,
      -1,  1124,    -1,  1082,    -1,  1113,    -1,  1090,    -1,  1053,
      -1,  1097,    -1,  1117,    -1,  1065,    -1,  1061,    -1,   791,
      -1,   792,    -1,    10,   108,    -1,    11,    -1,    10,   793,
     108,    -1,   794,    -1,  1139,    -1,   795,    -1,   794,   795,
      -1,   796,   797,   800,    -1,   157,    -1,   798,    -1,    -1,
     798,   799,    -1,  1071,    -1,  1082,    -1,  1113,    -1,  1074,
      -1,  1101,    -1,   801,    -1,    10,   158,    -1,    11,    -1,
      -1,   803,   804,   806,    -1,   183,    -1,   805,    -1,    -1,
    1130,    -1,   807,    -1,   808,    -1,    11,    -1,    10,   809,
     184,    -1,   810,   824,   838,   893,    -1,    -1,   811,   812,
     813,    -1,   185,    -1,  1127,    -1,   814,    -1,   815,    -1,
      10,   186,    -1,    11,    -1,    10,   816,   186,    -1,   817,
      -1,   818,    -1,   817,   818,    -1,   819,   820,   823,    -1,
     187,    -1,   821,    -1,    -1,   821,   822,    -1,  1071,    -1,
    1082,    -1,  1113,    -1,    10,   188,    -1,    11,    -1,    -1,
     825,   826,   827,    -1,   189,    -1,  1127,    -1,   828,    -1,
     829,    -1,    10,   190,    -1,    11,    -1,    10,   830,   190,
      -1,   831,    -1,   832,    -1,   831,   832,    -1,   833,   834,
     837,    -1,   187,    -1,   835,    -1,    -1,   835,   836,    -1,
    1071,    -1,  1082,    -1,  1074,    -1,  1101,    -1,    10,   188,
      -1,    11,    -1,    -1,   839,   840,    -1,   161,    -1,   841,
      -1,   842,    -1,    11,    -1,    10,   843,   162,    -1,   844,
     851,   858,   865,   872,   879,   886,    -1,    -1,   845,   846,
     847,    -1,   163,    -1,  1123,    -1,   848,    -1,   849,    -1,
      11,    -1,    10,   850,   164,    -1,  1181,    -1,    -1,   852,
     853,   854,    -1,   167,    -1,  1123,    -1,   855,    -1,   856,
      -1,    11,    -1,    10,   857,   168,    -1,  1181,    -1,    -1,
     859,   860,   861,    -1,   165,    -1,  1123,    -1,   862,    -1,
     863,    -1,    11,    -1,    10,   864,   166,    -1,  1181,    -1,
      -1,   866,   867,   868,    -1,   169,    -1,  1123,    -1,   869,
      -1,   870,    -1,    11,    -1,    10,   871,   170,    -1,  1181,
      -1,    -1,   873,   874,   875,    -1,   173,    -1,  1123,    -1,
     876,    -1,   877,    -1,    11,    -1,    10,   878,   174,    -1,
    1181,    -1,    -1,   880,   881,   882,    -1,   171,    -1,  1123,
      -1,   883,    -1,   884,    -1,    11,    -1,    10,   885,   172,
      -1,  1181,    -1,    -1,   887,   888,   889,    -1,   175,    -1,
    1123,    -1,   890,    -1,   891,    -1,    11,    -1,    10,   892,
     176,    -1,  1181,    -1,    -1,   893,   894,    -1,   895,   896,
     899,    -1,   107,    -1,   897,    -1,    -1,   897,   898,    -1,
    1127,    -1,  1124,    -1,  1082,    -1,  1113,    -1,  1090,    -1,
    1053,    -1,  1097,    -1,  1086,    -1,  1065,    -1,  1061,    -1,
     900,    -1,   901,    -1,    10,   108,    -1,    11,    -1,    10,
     902,   108,    -1,   903,    -1,  1139,    -1,   904,    -1,   903,
     904,    -1,   905,   906,   909,    -1,   187,    -1,   907,    -1,
      -1,   907,   908,    -1,  1071,    -1,  1082,    -1,  1113,    -1,
    1074,    -1,  1101,    -1,   910,    -1,    10,   188,    -1,    11,
      -1,    -1,   912,   913,   915,    -1,   191,    -1,   914,    -1,
      -1,  1129,    -1,   916,    -1,   917,    -1,    11,    -1,    10,
     918,   192,    -1,   919,   933,   947,  1002,    -1,    -1,   920,
     921,   922,    -1,   193,    -1,  1121,    -1,   923,    -1,   924,
      -1,    10,   194,    -1,    11,    -1,    10,   925,   194,    -1,
     926,    -1,   927,    -1,   926,   927,    -1,   928,   929,   932,
      -1,   195,    -1,   930,    -1,    -1,   930,   931,    -1,  1071,
      -1,  1082,    -1,  1113,    -1,    10,   196,    -1,    11,    -1,
      -1,   934,   935,   936,    -1,   197,    -1,  1121,    -1,   937,
      -1,   938,    -1,    10,   198,    -1,    11,    -1,    10,   939,
     198,    -1,   940,    -1,   941,    -1,   940,   941,    -1,   942,
     943,   946,    -1,   195,    -1,   944,    -1,    -1,   944,   945,
      -1,  1071,    -1,  1082,    -1,  1078,    -1,  1105,    -1,    10,
     196,    -1,    11,    -1,    -1,   948,   949,    -1,   161,    -1,
     950,    -1,   951,    -1,    11,    -1,    10,   952,   162,    -1,
     953,   960,   967,   974,   981,   988,   995,    -1,    -1,   954,
     955,   956,    -1,   163,    -1,  1123,    -1,   957,    -1,   958,
      -1,    11,    -1,    10,   959,   164,    -1,  1181,    -1,    -1,
     961,   962,   963,    -1,   167,    -1,  1123,    -1,   964,    -1,
     965,    -1,    11,    -1,    10,   966,   168,    -1,  1181,    -1,
      -1,   968,   969,   970,    -1,   165,    -1,  1123,    -1,   971,
      -1,   972,    -1,    11,    -1,    10,   973,   166,    -1,  1181,
      -1,    -1,   975,   976,   977,    -1,   169,    -1,  1123,    -1,
     978,    -1,   979,    -1,    11,    -1,    10,   980,   170,    -1,
    1181,    -1,    -1,   982,   983,   984,    -1,   173,    -1,  1123,
      -1,   985,    -1,   986,    -1,    11,    -1,    10,   987,   174,
      -1,  1181,    -1,    -1,   989,   990,   991,    -1,   171,    -1,
    1123,    -1,   992,    -1,   993,    -1,    11,    -1,    10,   994,
     172,    -1,  1181,    -1,    -1,   996,   997,   998,    -1,   175,
      -1,  1123,    -1,   999,    -1,  1000,    -1,    11,    -1,    10,
    1001,   176,    -1,  1181,    -1,    -1,  1002,  1003,    -1,  1004,
    1005,  1008,    -1,   107,    -1,  1006,    -1,    -1,  1006,  1007,
      -1,  1121,    -1,  1124,    -1,  1082,    -1,  1113,    -1,  1090,
      -1,  1053,    -1,  1097,    -1,  1057,    -1,  1065,    -1,  1061,
      -1,  1009,    -1,  1010,    -1,    10,   108,    -1,    11,    -1,
      10,  1011,   108,    -1,  1012,    -1,  1139,    -1,  1013,    -1,
    1012,  1013,    -1,  1014,  1015,  1018,    -1,   195,    -1,  1016,
      -1,    -1,  1016,  1017,    -1,  1071,    -1,  1082,    -1,  1113,
      -1,  1074,    -1,  1101,    -1,  1019,    -1,    10,   196,    -1,
      11,    -1,    -1,  1021,  1022,  1023,    -1,   199,    -1,  1136,
      -1,  1024,    -1,  1025,    -1,    11,    -1,    10,  1026,   200,
      -1,    -1,  1026,  1027,    -1,  1028,  1029,  1032,    -1,   201,
      -1,  1030,    -1,  1031,    -1,  1030,  1031,    -1,  1082,    -1,
    1113,    -1,  1090,    -1,  1053,    -1,  1097,    -1,  1061,    -1,
    1125,    -1,  1033,    -1,  1034,    -1,    10,   202,    -1,    11,
      -1,    10,  1035,   202,    -1,  1036,    -1,  1037,    -1,  1036,
    1037,    -1,  1038,    -1,  1039,    -1,  1040,    -1,   208,    -1,
     205,    -1,   206,  1041,   207,    -1,     5,    -1,  1043,    -1,
    1042,  1043,    -1,   129,    10,     4,   130,    -1,  1045,  1046,
    1052,    -1,   131,    -1,  1047,    -1,    -1,  1047,  1048,    -1,
    1049,    -1,  1050,    -1,  1051,    -1,    21,     3,     8,    -1,
      22,     3,     8,    -1,    23,     3,     8,    -1,    10,   132,
      -1,    11,    -1,  1054,    -1,  1055,    -1,  1056,    -1,    57,
      -1,    24,     3,  1150,    -1,  1058,    -1,  1059,    -1,  1060,
      -1,    48,    -1,    47,     3,     8,    -1,  1062,    -1,  1063,
      -1,  1064,    -1,    58,    -1,    46,     3,  1150,    -1,  1066,
      -1,  1067,    -1,  1068,    -1,    50,    -1,    49,     3,     8,
      -1,  1070,    -1,    26,     8,  1149,     8,    -1,  1072,    -1,
    1073,    -1,    42,  1150,     6,  1150,    -1,  1075,    -1,  1076,
      -1,  1077,    -1,    61,    -1,    63,     3,  1150,    -1,  1079,
      -1,  1080,    -1,  1081,    -1,    65,    -1,    67,  1150,  1149,
    1150,    -1,  1083,    -1,  1084,    -1,  1085,    -1,    56,    -1,
      41,     3,  1150,    -1,  1087,    -1,  1088,    -1,  1089,    -1,
      52,    -1,    51,     3,     8,    -1,  1091,    -1,  1092,    -1,
    1093,    -1,    70,    -1,    69,     3,  1150,    -1,  1095,    -1,
    1096,    -1,    43,  1150,     6,  1150,    -1,  1098,    -1,  1099,
      -1,  1100,    -1,    55,    -1,    25,     3,     8,    -1,  1102,
      -1,  1103,    -1,  1104,    -1,    62,    -1,    64,     3,  1150,
      -1,  1106,    -1,  1107,    -1,  1108,    -1,    66,    -1,    68,
    1150,  1149,  1150,    -1,  1110,    -1,  1111,    -1,  1112,    -1,
      59,    -1,    45,     3,     8,    -1,  1114,    -1,  1115,    -1,
    1116,    -1,    60,    -1,    44,     3,     8,    -1,  1118,    -1,
    1119,    -1,  1120,    -1,    54,    -1,    53,     3,     8,    -1,
      39,  1150,     6,  1150,    -1,    32,  1150,     6,  1150,    -1,
      40,  1150,     6,  1150,    -1,    17,  1150,     6,  1150,    -1,
      36,  1150,     6,  1150,    -1,    18,     8,     6,     8,    -1,
      38,  1150,     6,  1150,    -1,    31,  1150,     6,  1150,    -1,
      35,  1150,     6,  1150,    -1,    34,  1150,     6,  1150,    -1,
      16,  1150,     6,  1150,    -1,    33,  1150,     6,  1150,    -1,
      20,     8,     6,     8,    -1,    19,     8,     6,     8,    -1,
      27,     8,     6,     8,    -1,    28,  1150,     6,  1150,    -1,
      37,  1150,     6,  1150,    -1,    30,  1150,     6,  1150,    -1,
    1140,    -1,  1139,  1140,    -1,  1141,  1142,  1145,    -1,   203,
      -1,  1143,    -1,    -1,  1143,  1144,    -1,  1123,    -1,  1113,
      -1,  1061,    -1,  1146,    -1,  1147,    -1,    11,    -1,    10,
    1148,   204,    -1,  1181,    -1,     6,    -1,     7,    -1,  1151,
       8,    -1,    -1,  1151,  1152,    -1,   361,    -1,   362,    -1,
     363,    -1,   364,    -1,  1154,  1155,    -1,   216,    -1,  1156,
      -1,  1157,    -1,    10,   217,    -1,    11,    -1,    10,  1158,
     217,    -1,  1159,    -1,  1160,    -1,  1159,  1160,    -1,  1161,
      -1,  1165,    -1,  1169,    -1,  1173,    -1,  1177,    -1,    -1,
    1162,    -1,  1163,    -1,  1164,    -1,   221,    -1,   220,    -1,
     218,     5,   219,    -1,    -1,  1166,    -1,  1167,    -1,  1168,
      -1,   225,    -1,   224,    -1,   222,     5,   223,    -1,    -1,
    1170,    -1,  1171,    -1,  1172,    -1,   229,    -1,   228,    -1,
     226,     5,   227,    -1,    -1,  1174,    -1,  1175,    -1,  1176,
      -1,   233,    -1,   232,    -1,   230,     5,   231,    -1,    -1,
    1178,    -1,  1179,    -1,  1180,    -1,   237,    -1,   236,    -1,
     234,     5,   235,    -1,  1182,    -1,  1189,    -1,    -1,  1182,
    1183,    -1,  1184,  1185,  1188,    -1,   214,    -1,  1186,    -1,
      -1,  1186,  1187,    -1,  1195,    -1,  1194,    -1,    10,     6,
     215,    -1,   209,  1190,  1191,    -1,   213,  1150,     6,  1150,
      -1,  1192,    -1,  1193,    -1,    10,   210,    -1,    11,    -1,
      10,     4,   210,    -1,   211,  1150,     6,  1150,    -1,   212,
    1150,     6,  1150,    -1,   213,  1150,     6,  1150,    -1,  1192,
      -1,  1193,    -1,    10,   210,    -1,    11,    -1,    10,     4,
     210,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   283,   283,   284,   286,   293,   303,   303,   305,   305,
     307,   309,   311,   320,   321,   324,   332,   332,   345,   345,
     347,   363,   363,   365,   365,   367,   369,   371,   371,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     388,   390,   399,   399,   401,   401,   403,   405,   415,   417,
     424,   424,   426,   426,   428,   430,   440,   442,   448,   448,
     450,   450,   452,   454,   464,   471,   479,   480,   487,   493,
     493,   495,   495,   497,   499,   507,   509,   515,   515,   517,
     517,   519,   521,   530,   532,   539,   539,   541,   541,   543,
     545,   555,   557,   564,   564,   566,   566,   568,   570,   580,
     582,   588,   588,   590,   590,   592,   594,   604,   606,   612,
     612,   614,   614,   616,   618,   628,   635,   644,   645,   651,
     658,   658,   660,   660,   662,   664,   672,   678,   688,   696,
     701,   707,   707,   709,   711,   715,   715,   717,   725,   744,
     750,   750,   753,   757,   758,   761,   761,   770,   770,   772,
     782,   782,   784,   784,   786,   788,   790,   790,   793,   794,
     795,   796,   797,   801,   803,   813,   815,   815,   818,   819,
     822,   824,   832,   834,   844,   846,   846,   849,   850,   853,
     855,   864,   866,   876,   878,   878,   881,   882,   885,   887,
     896,   898,   906,   907,   909,   911,   922,   928,   938,   946,
     950,   955,   955,   957,   959,   963,   963,   965,   973,   992,
     997,   997,  1000,  1005,  1006,  1009,  1009,  1018,  1018,  1020,
    1027,  1027,  1029,  1029,  1031,  1033,  1035,  1035,  1038,  1039,
    1043,  1045,  1051,  1051,  1053,  1053,  1055,  1057,  1068,  1074,
    1084,  1092,  1096,  1101,  1101,  1103,  1105,  1109,  1109,  1111,
    1119,  1138,  1143,  1143,  1146,  1151,  1152,  1155,  1155,  1163,
    1163,  1165,  1185,  1185,  1187,  1187,  1189,  1191,  1193,  1193,
    1196,  1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,
    1206,  1207,  1208,  1209,  1210,  1215,  1221,  1231,  1232,  1234,
    1234,  1236,  1236,  1238,  1240,  1242,  1249,  1251,  1257,  1257,
    1259,  1259,  1261,  1263,  1273,  1284,  1294,  1296,  1296,  1298,
    1298,  1300,  1309,  1309,  1311,  1332,  1343,  1353,  1353,  1355,
    1355,  1357,  1368,  1379,  1389,  1389,  1391,  1391,  1393,  1404,
    1415,  1425,  1425,  1427,  1427,  1429,  1440,  1451,  1461,  1461,
    1463,  1463,  1465,  1476,  1492,  1502,  1504,  1504,  1506,  1506,
    1508,  1517,  1517,  1519,  1523,  1539,  1549,  1551,  1551,  1553,
    1553,  1555,  1564,  1564,  1566,  1570,  1586,  1596,  1598,  1598,
    1600,  1600,  1602,  1611,  1611,  1613,  1617,  1633,  1643,  1645,
    1645,  1647,  1647,  1649,  1658,  1658,  1660,  1664,  1675,  1685,
    1687,  1687,  1689,  1689,  1691,  1702,  1713,  1723,  1725,  1725,
    1727,  1727,  1729,  1754,  1765,  1775,  1777,  1777,  1779,  1779,
    1781,  1790,  1790,  1792,  1813,  1819,  1829,  1837,  1841,  1846,
    1846,  1848,  1850,  1854,  1854,  1856,  1864,  1883,  1889,  1889,
    1892,  1897,  1898,  1901,  1901,  1909,  1909,  1911,  1919,  1921,
    1921,  1924,  1930,  1936,  1944,  1944,  1946,  1948,  1950,  1957,
    1957,  1959,  1965,  1972,  1972,  1977,  1977,  1979,  1981,  1983,
    1993,  1993,  2008,  2013,  2024,  2032,  2041,  2041,  2043,  2045,
    2047,  2047,  2050,  2055,  2069,  2075,  2075,  2078,  2090,  2095,
    2103,  2103,  2107,  2107,  2122,  2127,  2138,  2146,  2155,  2155,
    2157,  2159,  2161,  2161,  2164,  2169,  2184,  2190,  2190,  2193,
    2205,  2210,  2216,  2216,  2220,  2220,  2222,  2227,  2227,  2229,
    2231,  2233,  2236,  2236,  2247,  2253,  2260,  2260,  2262,  2264,
    2266,  2270,  2270,  2282,  2288,  2295,  2295,  2297,  2299,  2301,
    2305,  2305,  2316,  2322,  2329,  2329,  2331,  2333,  2335,  2339,
    2339,  2350,  2356,  2363,  2363,  2365,  2367,  2369,  2373,  2373,
    2384,  2390,  2397,  2397,  2399,  2401,  2403,  2407,  2407,  2418,
    2424,  2431,  2431,  2433,  2435,  2437,  2441,  2441,  2452,  2458,
    2465,  2465,  2467,  2469,  2471,  2475,  2475,  2491,  2496,  2507,
    2515,  2524,  2524,  2526,  2528,  2534,  2534,  2536,  2541,  2557,
    2563,  2563,  2566,  2578,  2583,  2591,  2591,  2595,  2595,  2601,
    2607,  2615,  2623,  2631,  2631,  2633,  2635,  2635,  2637,  2656,
    2672,  2680,  2680,  2683,  2684,  2693,  2696,  2696,  2698,  2698,
    2700,  2705,  2705,  2707,  2712,  2743,  2763,  2763,  2766,  2770,
    2774,  2775,  2776,  2777,  2778,  2779,  2780,  2781,  2784,  2784,
    2786,  2786,  2788,  2790,  2790,  2792,  2792,  2795,  2810,  2830,
    2832,  2832,  2835,  2845,  2846,  2847,  2848,  2851,  2853,  2853,
    2861,  2861,  2863,  2869,  2876,  2876,  2881,  2881,  2883,  2885,
    2887,  2896,  2896,  2912,  2918,  2930,  2938,  2947,  2947,  2949,
    2951,  2953,  2953,  2956,  2961,  2976,  2978,  2978,  2981,  2992,
    2996,  3003,  3003,  3006,  3006,  3024,  3029,  3043,  3051,  3060,
    3060,  3062,  3064,  3066,  3066,  3069,  3074,  3092,  3094,  3094,
    3097,  3108,  3112,  3118,  3125,  3125,  3129,  3129,  3131,  3136,
    3136,  3138,  3140,  3142,  3145,  3145,  3156,  3162,  3169,  3169,
    3171,  3173,  3175,  3178,  3178,  3189,  3195,  3202,  3202,  3204,
    3206,  3208,  3211,  3211,  3222,  3228,  3235,  3235,  3237,  3239,
    3241,  3244,  3244,  3255,  3261,  3268,  3268,  3270,  3272,  3274,
    3277,  3277,  3288,  3294,  3301,  3301,  3303,  3305,  3307,  3310,
    3310,  3321,  3328,  3335,  3335,  3337,  3339,  3341,  3345,  3345,
    3356,  3362,  3369,  3369,  3371,  3373,  3375,  3379,  3379,  3381,
    3387,  3418,  3439,  3439,  3442,  3446,  3450,  3451,  3452,  3453,
    3454,  3455,  3456,  3457,  3460,  3460,  3462,  3462,  3464,  3466,
    3466,  3468,  3468,  3471,  3486,  3508,  3510,  3510,  3513,  3523,
    3524,  3525,  3526,  3529,  3531,  3531,  3539,  3539,  3541,  3547,
    3554,  3554,  3559,  3559,  3561,  3563,  3565,  3574,  3574,  3590,
    3595,  3606,  3614,  3623,  3623,  3625,  3627,  3629,  3629,  3632,
    3637,  3652,  3658,  3658,  3661,  3672,  3676,  3683,  3683,  3687,
    3687,  3705,  3710,  3723,  3731,  3740,  3740,  3742,  3744,  3746,
    3746,  3749,  3754,  3772,  3778,  3778,  3781,  3792,  3796,  3800,
    3806,  3806,  3810,  3810,  3812,  3817,  3817,  3819,  3821,  3823,
    3826,  3826,  3837,  3843,  3850,  3850,  3852,  3854,  3856,  3859,
    3859,  3870,  3876,  3883,  3883,  3885,  3887,  3889,  3893,  3893,
    3904,  3910,  3917,  3917,  3919,  3921,  3923,  3927,  3927,  3938,
    3944,  3951,  3951,  3953,  3955,  3957,  3961,  3961,  3972,  3978,
    3985,  3985,  3987,  3989,  3991,  3995,  3995,  4006,  4012,  4019,
    4019,  4021,  4023,  4025,  4029,  4029,  4040,  4046,  4053,  4053,
    4055,  4057,  4059,  4063,  4063,  4065,  4071,  4102,  4122,  4122,
    4125,  4129,  4133,  4134,  4135,  4136,  4137,  4138,  4139,  4140,
    4143,  4143,  4145,  4145,  4147,  4149,  4149,  4151,  4151,  4154,
    4169,  4189,  4191,  4191,  4194,  4204,  4205,  4206,  4207,  4210,
    4212,  4212,  4220,  4220,  4226,  4228,  4236,  4244,  4253,  4255,
    4257,  4257,  4261,  4281,  4299,  4305,  4305,  4308,  4309,  4310,
    4311,  4312,  4313,  4314,  4321,  4329,  4338,  4338,  4340,  4342,
    4344,  4344,  4346,  4353,  4364,  4366,  4366,  4368,  4370,  4387,
    4387,  4389,  4411,  4428,  4440,  4445,  4445,  4448,  4449,  4450,
    4452,  4461,  4470,  4479,  4479,  4485,  4492,  4492,  4494,  4499,
    4506,  4512,  4512,  4514,  4517,  4524,  4531,  4531,  4533,  4536,
    4543,  4549,  4549,  4551,  4554,  4562,  4569,  4576,  4583,  4585,
    4591,  4598,  4598,  4600,  4605,  4612,  4618,  4618,  4620,  4625,
    4631,  4638,  4638,  4640,  4645,  4652,  4658,  4658,  4660,  4663,
    4671,  4677,  4677,  4679,  4682,  4689,  4695,  4697,  4705,  4711,
    4711,  4713,  4716,  4723,  4730,  4730,  4732,  4737,  4744,  4750,
    4750,  4752,  4755,  4762,  4768,  4768,  4770,  4773,  4780,  4786,
    4786,  4788,  4791,  4798,  4804,  4804,  4806,  4809,  4821,  4830,
    4839,  4848,  4857,  4866,  4876,  4885,  4894,  4900,  4906,  4912,
    4918,  4932,  4942,  4953,  4959,  4968,  4989,  4989,  4991,  5009,
    5025,  5033,  5033,  5036,  5043,  5044,  5048,  5048,  5050,  5053,
    5055,  5059,  5060,  5067,  5069,  5069,  5071,  5072,  5073,  5074,
    5110,  5112,  5126,  5126,  5128,  5128,  5130,  5132,  5134,  5134,
    5137,  5138,  5139,  5140,  5141,  5143,  5143,  5151,  5151,  5153,
    5153,  5155,  5161,  5161,  5169,  5169,  5171,  5171,  5173,  5179,
    5179,  5187,  5187,  5189,  5189,  5191,  5197,  5197,  5205,  5205,
    5207,  5207,  5209,  5215,  5215,  5223,  5223,  5225,  5225,  5227,
    5239,  5247,  5249,  5249,  5251,  5253,  5262,  5264,  5264,  5266,
    5266,  5268,  5284,  5286,  5291,  5291,  5293,  5293,  5296,  5322,
    5330,  5387,  5392,  5392,  5394,  5394,  5396
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "ITEMTEXT", "INTEGER", "DOUBLE", "QUOTE", "TWOQUOTES", "GREATERTHAN",
  "ENDOFELEMENT", "OSOLSTART", "OSOLSTARTEMPTY", "OSOLATTRIBUTETEXT",
  "OSOLEND", "NUMBEROFOTHEROPTIONSATT", "NUMBEROFENUMERATIONSATT",
  "NUMBEROFJOBIDSATT", "NUMBEROFPATHSATT", "NUMBEROFPATHPAIRSATT",
  "FROMATT", "TOATT", "MAKECOPYATT", "CATEGORYATT", "TYPEATT",
  "GROUPWEIGHTATT", "NUMBEROFPROCESSESATT", "NUMBEROFSOLVEROPTIONSATT",
  "NUMBEROFSOSATT", "NUMBEROFVARIABLESATT", "NUMBEROFOBJECTIVESATT",
  "NUMBEROFCONSTRAINTSATT", "NUMBEROFOTHERVARIABLEOPTIONSATT",
  "NUMBEROFOTHEROBJECTIVEOPTIONSATT", "NUMBEROFOTHERCONSTRAINTOPTIONSATT",
  "NUMBEROFITEMSATT", "NUMBEROFVARATT", "NUMBEROFOBJATT", "NUMBEROFCONATT",
  "NUMBEROFELATT", "NAMEATT", "IDXATT", "SOSIDXATT", "VALUEATT", "UNITATT",
  "DESCRIPTIONATT", "CONTYPEATT", "EMPTYCONTYPEATT", "ENUMTYPEATT",
  "EMPTYENUMTYPEATT", "OBJTYPEATT", "EMPTYOBJTYPEATT", "VARTYPEATT",
  "EMPTYVARTYPEATT", "EMPTYTYPEATT", "EMPTYNAMEATT", "EMPTYCATEGORYATT",
  "EMPTYDESCRIPTIONATT", "EMPTYUNITATT", "EMPTYVALUEATT",
  "EMPTYLBVALUEATT", "EMPTYUBVALUEATT", "LBVALUEATT", "UBVALUEATT",
  "EMPTYLBDUALVALUEATT", "EMPTYUBDUALVALUEATT", "LBDUALVALUEATT",
  "UBDUALVALUEATT", "SOLVERATT", "EMPTYSOLVERATT", "WEIGHTATT",
  "EMPTYWEIGHTATT", "TRANSPORTTYPEATT", "LOCATIONTYPEATT", "GENERALSTART",
  "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND",
  "JOBSTART", "JOBEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND",
  "SERVICEURISTART", "SERVICEURIEND", "SERVICENAMESTART", "SERVICENAMEEND",
  "INSTANCENAMESTART", "INSTANCENAMEEND", "INSTANCELOCATIONSTART",
  "INSTANCELOCATIONEND", "JOBIDSTART", "JOBIDEND", "SOLVERTOINVOKESTART",
  "SOLVERTOINVOKEEND", "LICENSESTART", "LICENSEEND", "USERNAMESTART",
  "USERNAMEEND", "PASSWORDSTART", "PASSWORDEND", "CONTACTSTART",
  "CONTACTEND", "OTHEROPTIONSSTART", "OTHEROPTIONSEND", "OTHERSTART",
  "OTHEREND", "MINDISKSPACESTART", "MINDISKSPACEEND", "MINMEMORYSTART",
  "MINMEMORYEND", "MINCPUSPEEDSTART", "MINCPUSPEEDEND",
  "MINCPUNUMBERSTART", "MINCPUNUMBEREND", "SERVICETYPESTART",
  "SERVICETYPEEND", "MAXTIMESTART", "MAXTIMEEND",
  "REQUESTEDSTARTTIMESTART", "REQUESTEDSTARTTIMEEND", "DEPENDENCIESSTART",
  "DEPENDENCIESEND", "REQUIREDDIRECTORIESSTART", "REQUIREDDIRECTORIESEND",
  "REQUIREDFILESSTART", "REQUIREDFILESEND", "PATHSTART", "PATHEND",
  "PATHPAIRSTART", "PATHPAIREND", "DIRECTORIESTOMAKESTART",
  "DIRECTORIESTOMAKEEND", "FILESTOMAKESTART", "FILESTOMAKEEND",
  "DIRECTORIESTODELETESTART", "DIRECTORIESTODELETEEND",
  "FILESTODELETESTART", "FILESTODELETEEND", "INPUTDIRECTORIESTOMOVESTART",
  "INPUTDIRECTORIESTOMOVEEND", "INPUTFILESTOMOVESTART",
  "INPUTFILESTOMOVEEND", "OUTPUTDIRECTORIESTOMOVESTART",
  "OUTPUTDIRECTORIESTOMOVEEND", "OUTPUTFILESTOMOVESTART",
  "OUTPUTFILESTOMOVEEND", "PROCESSESTOKILLSTART", "PROCESSESTOKILLEND",
  "PROCESSSTART", "PROCESSEND", "VARIABLESSTART", "VARIABLESEND",
  "INITIALVARIABLEVALUESSTART", "INITIALVARIABLEVALUESEND", "VARSTART",
  "VAREND", "INITIALVARIABLEVALUESSTRINGSTART",
  "INITIALVARIABLEVALUESSTRINGEND", "INITIALBASISSTATUSSTART",
  "INITIALBASISSTATUSEND", "BASICSTART", "BASICEND", "ATUPPERSTART",
  "ATUPPEREND", "ATLOWERSTART", "ATLOWEREND", "ATEQUALITYSTART",
  "ATEQUALITYEND", "SUPERBASICSTART", "SUPERBASICEND", "ISFREESTART",
  "ISFREEEND", "UNKNOWNSTART", "UNKNOWNEND",
  "INTEGERVARIABLEBRANCHINGWEIGHTSSTART",
  "INTEGERVARIABLEBRANCHINGWEIGHTSEND", "SOSVARIABLEBRANCHINGWEIGHTSSTART",
  "SOSVARIABLEBRANCHINGWEIGHTSEND", "SOSSTART", "SOSEND",
  "OBJECTIVESSTART", "OBJECTIVESEND", "INITIALOBJECTIVEVALUESSTART",
  "INITIALOBJECTIVEVALUESEND", "OBJSTART", "OBJEND",
  "INITIALOBJECTIVEBOUNDSSTART", "INITIALOBJECTIVEBOUNDSEND",
  "CONSTRAINTSSTART", "CONSTRAINTSEND", "INITIALCONSTRAINTVALUESSTART",
  "INITIALCONSTRAINTVALUESEND", "CONSTART", "CONEND",
  "INITIALDUALVALUESSTART", "INITIALDUALVALUESEND", "SOLVEROPTIONSSTART",
  "SOLVEROPTIONSEND", "SOLVEROPTIONSTART", "SOLVEROPTIONEND",
  "ENUMERATIONSTART", "ENUMERATIONEND", "ITEMEMPTY", "ITEMSTART",
  "ITEMEND", "ITEMSTARTANDEND", "BASE64START", "BASE64END", "INCRATT",
  "MULTATT", "SIZEOFATT", "ELSTART", "ELEND", "HEADERSTART", "HEADEREND",
  "FILENAMESTART", "FILENAMEEND", "FILENAMEEMPTY", "FILENAMESTARTANDEND",
  "FILESOURCESTART", "FILESOURCEEND", "FILESOURCEEMPTY",
  "FILESOURCESTARTANDEND", "FILEDESCRIPTIONSTART", "FILEDESCRIPTIONEND",
  "FILEDESCRIPTIONEMPTY", "FILEDESCRIPTIONSTARTANDEND", "FILECREATORSTART",
  "FILECREATOREND", "FILECREATOREMPTY", "FILECREATORSTARTANDEND",
  "FILELICENCESTART", "FILELICENCEEND", "FILELICENCEEMPTY",
  "FILELICENCESTARTANDEND", "MATRIXSTART", "MATRIXEND", "BASEMATRIXEND",
  "BASEMATRIXSTART", "BLOCKSTART", "BLOCKEND", "BLOCKSSTART", "BLOCKSEND",
  "EMPTYSYMMETRYATT", "SYMMETRYATT", "EMPTYEXCLUDEATT", "EXCLUDEATT",
  "CONSTANTATT", "NUMBEROFBLOCKSATT", "NUMBEROFCOLUMNSATT",
  "NUMBEROFROWSATT", "NUMBEROFVARIDXATT", "BASEMATRIXIDXATT",
  "TARGETMATRIXFIRSTROWATT", "TARGETMATRIXFIRSTCOLATT",
  "BASEMATRIXSTARTROWATT", "BASEMATRIXSTARTCOLATT", "BASEMATRIXENDROWATT",
  "BASEMATRIXENDCOLATT", "SCALARMULTIPLIERATT", "EMPTYBASETRANSPOSEATT",
  "BASETRANSPOSEATT", "ELEMENTSSTART", "ELEMENTSEND",
  "CONSTANTELEMENTSSTART", "CONSTANTELEMENTSEND", "STARTVECTORSTART",
  "STARTVECTOREND", "NONZEROSSTART", "NONZEROSEND", "INDEXESSTART",
  "INDEXESEND", "VALUESSTART", "VALUESEND", "VARREFERENCEELEMENTSSTART",
  "VARREFERENCEELEMENTSEND", "LINEARELEMENTSSTART", "LINEARELEMENTSEND",
  "GENERALELEMENTSSTART", "GENERALELEMENTSEND",
  "CONREFERENCEELEMENTSSTART", "CONREFERENCEELEMENTSEND",
  "OBJREFERENCEELEMENTSSTART", "OBJREFERENCEELEMENTSEND",
  "PATTERNELEMENTSSTART", "PATTERNELEMENTSEND", "VARIDXSTART", "VARIDXEND",
  "TRANSFORMATIONSTART", "TRANSFORMATIONEND", "COLOFFSETSSTART",
  "COLOFFSETSEND", "ROWOFFSETSSTART", "ROWOFFSETSEND", "EMPTYROWMAJORATT",
  "ROWMAJORATT", "BLOCKROWIDXATT", "BLOCKCOLIDXATT", "DUMMY",
  "NONLINEAREXPRESSIONSSTART", "NONLINEAREXPRESSIONSEND",
  "NUMBEROFNONLINEAREXPRESSIONS", "NLSTART", "NLEND", "POWERSTART",
  "POWEREND", "PLUSSTART", "PLUSEND", "MINUSSTART", "MINUSEND",
  "DIVIDESTART", "DIVIDEEND", "LNSTART", "LNEND", "SQRTSTART", "SQRTEND",
  "SUMSTART", "SUMEND", "PRODUCTSTART", "PRODUCTEND", "EXPSTART", "EXPEND",
  "NEGATESTART", "NEGATEEND", "IFSTART", "IFEND", "SQUARESTART",
  "SQUAREEND", "COSSTART", "COSEND", "SINSTART", "SINEND", "VARIABLESTART",
  "VARIABLEEND", "ABSSTART", "ABSEND", "ERFSTART", "ERFEND", "MAXSTART",
  "MAXEND", "ALLDIFFSTART", "ALLDIFFEND", "MINSTART", "MINEND", "ESTART",
  "EEND", "PISTART", "PIEND", "TIMESSTART", "TIMESEND", "NUMBERSTART",
  "NUMBEREND", "MATRIXTRACESTART", "MATRIXTRACEEND", "MATRIXTOSCALARSTART",
  "MATRIXTOSCALAREND", "IDATT", "COEFATT", "' '", "'\\t'", "'\\r'",
  "'\\n'", "$accept", "osoldoc", "osolStartEmpty", "osolStart",
  "osolAttributes", "osolContent", "osolEmpty", "osolLaden", "osolEnd",
  "osolEnding", "osolBody", "headerElement", "generalElement",
  "generalElementStart", "generalElementContent", "generalElementEmpty",
  "generalElementLaden", "generalElementBody", "generalElementList",
  "generalChild", "serviceURI", "serviceURIStart", "serviceURIContent",
  "serviceURIEmpty", "serviceURILaden", "serviceURIBody", "serviceName",
  "serviceNameStart", "serviceNameContent", "serviceNameEmpty",
  "serviceNameLaden", "serviceNameBody", "instanceName",
  "instanceNameStart", "instanceNameContent", "instanceNameEmpty",
  "instanceNameLaden", "instanceNameBody", "instanceLocation",
  "instanceLocationStart", "instanceLocationAttributes",
  "locationTypeAttribute", "instanceLocationContent",
  "instanceLocationEmpty", "instanceLocationLaden", "instanceLocationBody",
  "jobID", "jobIDStart", "jobIDContent", "jobIDEmpty", "jobIDLaden",
  "jobIDBody", "solverToInvoke", "solverToInvokeStart",
  "solverToInvokeContent", "solverToInvokeEmpty", "solverToInvokeLaden",
  "solverToInvokeBody", "license", "licenseStart", "licenseContent",
  "licenseEmpty", "licenseLaden", "licensebody", "username",
  "usernameStart", "usernameContent", "usernameEmpty", "usernameLaden",
  "usernamebody", "password", "passwordStart", "passwordContent",
  "passwordEmpty", "passwordLaden", "passwordbody", "contact",
  "contactStart", "contactAttributes", "transportTypeAttribute",
  "contactContent", "contactContentEmpty", "contactContentLaden",
  "contactBody", "otherGeneralOptions", "otherGeneralOptionsStart",
  "otherGeneralOptionsAttributes", "otherGeneralOptionsContent",
  "otherGeneralOptionsEmpty", "otherGeneralOptionsLaden",
  "otherGeneralOptionsBody", "otherGeneralOptionArray",
  "otherGeneralOption", "otherGeneralOptionStart",
  "otherGeneralAttributes", "otherGeneralAttList", "otherGeneralAtt",
  "otherGeneralEnd", "systemElement", "systemElementStart",
  "systemElementContent", "systemElementEmpty", "systemElementLaden",
  "systemElementBody", "systemElementList", "systemChild", "minDiskSpace",
  "minDiskSpaceStart", "minDiskSpaceAttributes", "minDiskSpaceAttList",
  "minDiskSpaceAtt", "minDiskSpaceContent", "minDiskSpaceValue",
  "minMemorySize", "minMemoryStart", "minMemoryAttributes",
  "minMemoryAttList", "minMemoryAtt", "minMemoryContent", "minMemoryValue",
  "minCPUSpeed", "minCPUSpeedStart", "minCPUSpeedAttributes",
  "minCPUSpeedAttList", "minCPUSpeedAtt", "minCPUSpeedContent",
  "minCPUSpeedValue", "minCPUNumber", "minCPUNumberStart",
  "minCPUNumberAttributes", "minCPUNumberContent", "minCPUNumberValue",
  "otherSystemOptions", "otherSystemOptionsStart",
  "otherSystemOptionsAttributes", "otherSystemOptionsContent",
  "otherSystemOptionsEmpty", "otherSystemOptionsLaden",
  "otherSystemOptionsBody", "otherSystemOptionArray", "otherSystemOption",
  "otherSystemOptionStart", "otherSystemOptionAttributes",
  "otherSystemOptionAttList", "otherSystemOptionAtt",
  "otherSystemOptionEnd", "serviceElement", "serviceElementStart",
  "serviceElementContent", "serviceElementEmpty", "serviceElementLaden",
  "serviceElementBody", "serviceElementList", "serviceChild",
  "serviceType", "serviceTypeStart", "serviceTypeContent",
  "serviceTypeEmpty", "serviceTypeLaden", "serviceTypeBody",
  "otherServiceOptions", "otherServiceOptionsStart",
  "otherServiceOptionsAttributes", "otherServiceOptionsContent",
  "otherServiceOptionsEmpty", "otherServiceOptionsLaden",
  "otherServiceOptionsBody", "otherServiceOptionArray",
  "otherServiceOption", "otherServiceOptionStart",
  "otherServiceOptionAttributes", "otherServiceOptionAttList",
  "otherServiceOptionAtt", "otherServiceOptionEnd", "jobElement",
  "jobElementStart", "jobElementContent", "jobElementEmpty",
  "jobElementLaden", "jobElementBody", "jobElementList", "jobChild",
  "maxTime", "maxTimeStart", "maxTimeAttributes", "maxTimeContent",
  "maxTimeEmpty", "maxTimeLaden", "maxTimeBody", "maxTimeValue",
  "requestedStartTime", "requestedStartTimeStart",
  "requestedStartTimeContent", "requestedStartTimeEmpty",
  "requestedStartTimeLaden", "requestedStartTimeBody", "dependencies",
  "dependenciesStart", "dependenciesAttributes", "dependenciesContent",
  "dependenciesEmpty", "dependenciesLaden", "dependenciesList",
  "dependencyJobID", "requiredDirectories", "requiredDirectoriesStart",
  "requiredDirectoriesContent", "requiredDirectoriesEmpty",
  "requiredDirectoriesLaden", "requiredFiles", "requiredFilesStart",
  "requiredFilesContent", "requiredFilesEmpty", "requiredFilesLaden",
  "directoriesToMake", "directoriesToMakeStart",
  "directoriesToMakeContent", "directoriesToMakeEmpty",
  "directoriesToMakeLaden", "filesToMake", "filesToMakeStart",
  "filesToMakeContent", "filesToMakeEmpty", "filesToMakeLaden",
  "inputDirectoriesToMove", "inputDirectoriesToMoveStart",
  "inputDirectoriesToMoveAttributes", "inputDirectoriesToMoveContent",
  "inputDirectoriesToMoveEmpty", "inputDirectoriesToMoveLaden",
  "inputDirectoriesToMoveList", "inputDirectoryToMove", "inputFilesToMove",
  "inputFilesToMoveStart", "inputFilesToMoveAttributes",
  "inputFilesToMoveContent", "inputFilesToMoveEmpty",
  "inputFilesToMoveLaden", "inputFilesToMoveList", "inputFileToMove",
  "outputFilesToMove", "outputFilesToMoveStart",
  "outputFilesToMoveAttributes", "outputFilesToMoveContent",
  "outputFilesToMoveEmpty", "outputFilesToMoveLaden",
  "outputFilesToMoveList", "outputFileToMove", "outputDirectoriesToMove",
  "outputDirectoriesToMoveStart", "outputDirectoriesToMoveAttributes",
  "outputDirectoriesToMoveContent", "outputDirectoriesToMoveEmpty",
  "outputDirectoriesToMoveLaden", "outputDirectoriesToMoveList",
  "outputDirectoryToMove", "filesToDelete", "filesToDeleteStart",
  "filesToDeleteAttributes", "filesToDeleteContent", "filesToDeleteEmpty",
  "filesToDeleteLaden", "directoriesToDelete", "directoriesToDeleteStart",
  "directoriesToDeleteAttributes", "directoriesToDeleteContent",
  "directoriesToDeleteEmpty", "directoriesToDeleteLaden",
  "processesToKill", "processesToKillStart", "processesToKillAttributes",
  "processesToKillContent", "processesToKillEmpty", "processesToKillLaden",
  "processesToKillList", "processID", "otherJobOptions",
  "otherJobOptionsStart", "otherJobOptionsAttributes",
  "otherJobOptionsContent", "otherJobOptionsEmpty", "otherJobOptionsLaden",
  "otherJobOptionsBody", "otherJobOptionArray", "otherJobOption",
  "otherJobOptionStart", "otherJobOptionAttributes",
  "otherJobOptionAttList", "otherJobOptionAtt", "otherJobOptionEnd",
  "optimizationElement", "optimizationStart", "optimizationAttributes",
  "optimizationAttList", "optimizationATT", "optimizationContent",
  "optimizationEmpty", "optimizationLaden", "optimizationBody",
  "variables", "variablesStart", "variablesAttributes",
  "numberOfOtherVariableOptions", "variablesContent", "variablesEmpty",
  "variablesLaden", "variablesBody", "initialVariableValues",
  "initialVariableValuesStart", "initialVariableValuesAttributes",
  "initialVariableValuesContent", "initialVariableValuesEmpty",
  "initialVariableValuesLaden", "initialVariableValuesBody",
  "initVarValueArray", "initVarValue", "initVarValueStart",
  "initVarValueAttributes", "initVarValueAttList", "initVarValueAtt",
  "initVarValueContent", "initialVariableValuesString",
  "initialVariableValuesStringStart",
  "initialVariableValuesStringAttributes",
  "initialVariableValuesStringContent", "initialVariableValuesStringEmpty",
  "initialVariableValuesStringLaden", "initialVariableValuesStringBody",
  "initVarValueStringArray", "initVarValueString",
  "initVarValueStringStart", "initVarValueStringAttributes",
  "initVarValueStringAttList", "initVarValueStringAtt",
  "initVarValueStringContent", "variableInitialBasis",
  "variableInitialBasisStart", "variableInitialBasisContent",
  "variableInitialBasisEmpty", "variableInitialBasisLaden",
  "variableInitialBasisBody", "variablesBasic", "variablesBasicStart",
  "variablesBasicNumberOfElATT", "variablesBasicContent",
  "variablesBasicEmpty", "variablesBasicLaden", "variablesBasicBody",
  "variablesAtLower", "variablesAtLowerStart",
  "variablesAtLowerNumberOfElATT", "variablesAtLowerContent",
  "variablesAtLowerEmpty", "variablesAtLowerLaden", "variablesAtLowerBody",
  "variablesAtUpper", "variablesAtUpperStart",
  "variablesAtUpperNumberOfElATT", "variablesAtUpperContent",
  "variablesAtUpperEmpty", "variablesAtUpperLaden", "variablesAtUpperBody",
  "variablesAtEquality", "variablesAtEqualityStart",
  "variablesAtEqualityNumberOfElATT", "variablesAtEqualityContent",
  "variablesAtEqualityEmpty", "variablesAtEqualityLaden",
  "variablesAtEqualityBody", "variablesIsFree", "variablesIsFreeStart",
  "variablesIsFreeNumberOfElATT", "variablesIsFreeContent",
  "variablesIsFreeEmpty", "variablesIsFreeLaden", "variablesIsFreeBody",
  "variablesSuperbasic", "variablesSuperbasicStart",
  "variablesSuperbasicNumberOfElATT", "variablesSuperbasicContent",
  "variablesSuperbasicEmpty", "variablesSuperbasicLaden",
  "variablesSuperbasicBody", "variablesUnknown", "variablesUnknownStart",
  "variablesUnknownNumberOfElATT", "variablesUnknownContent",
  "variablesUnknownEmpty", "variablesUnknownLaden", "variablesUnknownBody",
  "integerVariableBranchingWeights",
  "integerVariableBranchingWeightsStart",
  "integerVariableBranchingWeightsAttributes",
  "integerVariableBranchingWeightsContent",
  "integerVariableBranchingWeightsEmpty",
  "integerVariableBranchingWeightsLaden",
  "integerVariableBranchingWeightsBody", "branchingWeightsArray",
  "branchingWeight", "branchingWeightStart", "branchingWeightAttributes",
  "branchingWeightAttList", "branchingWeightAtt", "branchingWeightContent",
  "sosVariableBranchingWeights", "sosVariableBranchingWeightsStart",
  "sosVariableBranchingWeightsAttributes",
  "sosVariableBranchingWeightsContent", "sosVariableBranchingWeightsEmpty",
  "sosVariableBranchingWeightsLaden", "sosWeightGroupArray",
  "sosWeightGroup", "sosWeightGroupStart", "sosWeightGroupAttributes",
  "sosWeightGroupAttList", "sosWeightGroupAtt", "sosWeightGroupContent",
  "sosWeightGroupEmpty", "sosWeightGroupLaden",
  "otherVariableOptionsArray", "otherVariableOption",
  "otherVariableOptionStart", "otherVariableOptionAttributes",
  "otherVariableOptionAttList", "otherVariableOptionATT",
  "otherVariableOptionContent", "otherVariableOptionEmpty",
  "otherVariableOptionLaden", "otherVariableOptionBody", "otherVarList",
  "otherVar", "otherVarStart", "otherVarAttributes", "otherVarAttList",
  "otherVarAtt", "otherVarContent", "otherVarEmpty", "objectives",
  "objectivesStart", "objectivesAttributes",
  "numberOfOtherObjectiveOptions", "objectivesContent", "objectivesEmpty",
  "objectivesLaden", "objectivesBody", "initialObjectiveValues",
  "initialObjectiveValuesStart", "initialObjectiveValuesAttributes",
  "initialObjectiveValuesContent", "initialObjectiveValuesEmpty",
  "initialObjectiveValuesLaden", "initialObjectiveValuesBody",
  "initObjValueArray", "initObjValue", "initObjValueStart",
  "initObjValueAttributes", "initObjValueAttList", "initObjValueAtt",
  "initObjValueContent", "initialObjectiveBounds",
  "initialObjectiveBoundsStart", "numberOfObjATT",
  "initialObjectiveBoundsContent", "initialObjectiveBoundsEmpty",
  "initialObjectiveBoundsLaden", "initialObjectiveBoundsBody",
  "initObjBoundArray", "initObjBound", "initObjBoundStart",
  "initObjBoundAttributes", "initObjBoundAttList", "initObjBoundAtt",
  "initObjBoundContent", "objectiveInitialBasis",
  "objectiveInitialBasisStart", "objectiveInitialBasisContent",
  "objectiveInitialBasisEmpty", "objectiveInitialBasisLaden",
  "objectiveInitialBasisBody", "objectivesBasic", "objectivesBasicStart",
  "objectivesBasicNumberOfElATT", "objectivesBasicContent",
  "objectivesBasicEmpty", "objectivesBasicLaden", "objectivesBasicBody",
  "objectivesAtLower", "objectivesAtLowerStart",
  "objectivesAtLowerNumberOfElATT", "objectivesAtLowerContent",
  "objectivesAtLowerEmpty", "objectivesAtLowerLaden",
  "objectivesAtLowerBody", "objectivesAtUpper", "objectivesAtUpperStart",
  "objectivesAtUpperNumberOfElATT", "objectivesAtUpperContent",
  "objectivesAtUpperEmpty", "objectivesAtUpperLaden",
  "objectivesAtUpperBody", "objectivesAtEquality",
  "objectivesAtEqualityStart", "objectivesAtEqualityNumberOfElATT",
  "objectivesAtEqualityContent", "objectivesAtEqualityEmpty",
  "objectivesAtEqualityLaden", "objectivesAtEqualityBody",
  "objectivesIsFree", "objectivesIsFreeStart",
  "objectivesIsFreeNumberOfElATT", "objectivesIsFreeContent",
  "objectivesIsFreeEmpty", "objectivesIsFreeLaden", "objectivesIsFreeBody",
  "objectivesSuperbasic", "objectivesSuperbasicStart",
  "objectivesSuperbasicNumberOfElATT", "objectivesSuperbasicContent",
  "objectivesSuperbasicEmpty", "objectivesSuperbasicLaden",
  "objectivesSuperbasicBody", "objectivesUnknown",
  "objectivesUnknownStart", "objectivesUnknownNumberOfElATT",
  "objectivesUnknownContent", "objectivesUnknownEmpty",
  "objectivesUnknownLaden", "objectivesUnknownBody",
  "otherObjectiveOptionsArray", "otherObjectiveOption",
  "otherObjectiveOptionStart", "otherObjectiveOptionAttributes",
  "otherObjectiveOptionAttList", "otherObjectiveOptionATT",
  "otherObjectiveOptionContent", "otherObjectiveOptionEmpty",
  "otherObjectiveOptionLaden", "otherObjectiveOptionBody", "otherObjList",
  "otherObj", "otherObjStart", "otherObjAttributes", "otherObjAttList",
  "otherObjAtt", "otherObjContent", "otherObjEmpty", "constraints",
  "constraintsStart", "constraintsAttributes",
  "numberOfOtherConstraintOptions", "constraintsContent",
  "constraintsEmpty", "constraintsLaden", "constraintsBody",
  "initialConstraintValues", "initialConstraintValuesStart",
  "initialConstraintValuesAttributes", "initialConstraintValuesContent",
  "initialConstraintValuesEmpty", "initialConstraintValuesLaden",
  "initialConstraintValuesBody", "initConValueArray", "initConValue",
  "initConValueStart", "initConValueAttributes", "initConValueAttList",
  "initConValueAtt", "initConValueContent", "initialDualValues",
  "initialDualValuesStart", "initialDualValuesAttributes",
  "initialDualValuesContent", "initialDualValuesEmpty",
  "initialDualValuesLaden", "initialDualValuesBody", "initDualValueArray",
  "initDualValue", "initDualValueStart", "initDualValueAttributes",
  "initDualValueAttList", "initDualValueAtt", "initDualValueContent",
  "slacksInitialBasis", "slacksInitialBasisStart",
  "slacksInitialBasisContent", "slacksInitialBasisEmpty",
  "slacksInitialBasisLaden", "slacksInitialBasisBody", "slacksBasic",
  "slacksBasicStart", "slacksBasicNumberOfElATT", "slacksBasicContent",
  "slacksBasicEmpty", "slacksBasicLaden", "slacksBasicBody",
  "slacksAtLower", "slacksAtLowerStart", "slacksAtLowerNumberOfElATT",
  "slacksAtLowerContent", "slacksAtLowerEmpty", "slacksAtLowerLaden",
  "slacksAtLowerBody", "slacksAtUpper", "slacksAtUpperStart",
  "slacksAtUpperNumberOfElATT", "slacksAtUpperContent",
  "slacksAtUpperEmpty", "slacksAtUpperLaden", "slacksAtUpperBody",
  "slacksAtEquality", "slacksAtEqualityStart",
  "slacksAtEqualityNumberOfElATT", "slacksAtEqualityContent",
  "slacksAtEqualityEmpty", "slacksAtEqualityLaden", "slacksAtEqualityBody",
  "slacksIsFree", "slacksIsFreeStart", "slacksIsFreeNumberOfElATT",
  "slacksIsFreeContent", "slacksIsFreeEmpty", "slacksIsFreeLaden",
  "slacksIsFreeBody", "slacksSuperbasic", "slacksSuperbasicStart",
  "slacksSuperbasicNumberOfElATT", "slacksSuperbasicContent",
  "slacksSuperbasicEmpty", "slacksSuperbasicLaden", "slacksSuperbasicBody",
  "slacksUnknown", "slacksUnknownStart", "slacksUnknownNumberOfElATT",
  "slacksUnknownContent", "slacksUnknownEmpty", "slacksUnknownLaden",
  "slacksUnknownBody", "otherConstraintOptionsArray",
  "otherConstraintOption", "otherConstraintOptionStart",
  "otherConstraintOptionAttributes", "otherConstraintOptionAttList",
  "otherConstraintOptionATT", "otherConstraintOptionContent",
  "otherConstraintOptionEmpty", "otherConstraintOptionLaden",
  "otherConstraintOptionBody", "otherConList", "otherCon", "otherConStart",
  "otherConAttributes", "otherConAttList", "otherConAtt",
  "otherConContent", "otherConEmpty", "solverOptions",
  "solverOptionsStart", "numberOfSolverOptionsATT", "solverOptionsContent",
  "solverOptionsEmpty", "solverOptionsLaden", "solverOptionArray",
  "solverOption", "solverOptionStart", "solverOptionAttributes",
  "solverOptionAttList", "solverOptionATT", "solverOptionContent",
  "solverOptionEmpty", "solverOptionLaden", "solverOptionBody",
  "solverOptionItemArray", "solverOptionItem", "solverOptionItemContent",
  "solverOptionItemEmpty", "solverOptionItemLaden", "solverOptionItemBody",
  "PathList", "Path", "PathPair", "PathPairStart", "PathPairAttributes",
  "PathPairAttList", "PathPairAttribute", "PathPairFromATT",
  "PathPairToATT", "PathPairMakeCopyATT", "PathPairEnd",
  "categoryAttribute", "categoryAtt", "categoryAttEmpty",
  "categoryAttContent", "conTypeAttribute", "conTypeAtt",
  "conTypeAttEmpty", "conTypeAttContent", "descriptionAttribute",
  "descriptionAtt", "descriptionAttEmpty", "descriptionAttContent",
  "enumTypeAttribute", "enumTypeAtt", "enumTypeAttEmpty",
  "enumTypeAttContent", "groupWeightAttribute", "groupWeightAtt",
  "idxAttribute", "idxAtt", "idxAttContent", "lbValueAttribute",
  "lbValueAtt", "lbValueAttEmpty", "lbValueAttContent",
  "lbDualValueAttribute", "lbDualValueAtt", "lbDualValueAttEmpty",
  "lbDualValueAttContent", "nameAttribute", "nameAtt", "nameAttEmpty",
  "nameAttContent", "objTypeAttribute", "objTypeAtt", "objTypeAttEmpty",
  "objTypeAttContent", "solverAttribute", "solverAtt", "solverAttEmpty",
  "solverAttContent", "sosIdxAttribute", "sosIdxAtt", "sosIdxAttContent",
  "typeAttribute", "typeAtt", "typeAttEmpty", "typeAttContent",
  "ubValueAttribute", "ubValueAtt", "ubValueAttEmpty", "ubValueAttContent",
  "ubDualValueAttribute", "ubDualValueAtt", "ubDualValueAttEmpty",
  "ubDualValueAttContent", "unitAttribute", "unitAtt", "unitAttEmpty",
  "unitAttContent", "valueAttribute", "valueAtt", "valueAttEmpty",
  "valueAttContent", "varTypeAttribute", "varTypeAtt", "varTypeAttEmpty",
  "varTypeAttContent", "numberOfConAttribute",
  "numberOfConstraintsAttribute", "numberOfElAttribute",
  "numberOfEnumerationsAttribute", "numberOfItemsAttribute",
  "numberOfJobIDsATT", "numberOfObjAttribute",
  "numberOfObjectivesAttribute", "numberOfOtherConstraintOptionsAttribute",
  "numberOfOtherObjectiveOptionsAttribute",
  "numberOfOtherOptionsAttribute", "numberOfOtherVariableOptionsAttribute",
  "numberOfPathPairsAttribute", "numberOfPathsAttribute",
  "numberOfProcessesATT", "numberOfSolverOptionsAttribute",
  "numberOfVarAttribute", "numberOfVariablesAttribute",
  "otherEnumerationList", "otherEnumeration", "otherEnumerationStart",
  "otherEnumerationAttributes", "otherEnumerationAttList",
  "otherEnumerationATT", "otherEnumerationContent",
  "otherEnumerationEmpty", "otherEnumerationLaden", "otherEnumerationBody",
  "aNumber", "quote", "xmlWhiteSpace", "xmlWhiteSpaceChar",
  "osglFileHeader", "headerElementStart", "headerElementContent",
  "headerElementEmpty", "headerElementLaden", "headerElementBody",
  "headerElementList", "headerChild", "fileName", "fileNameContent",
  "fileNameEmpty", "fileNameLaden", "fileSource", "fileSourceContent",
  "fileSourceEmpty", "fileSourceLaden", "fileDescription",
  "fileDescriptionContent", "fileDescriptionEmpty", "fileDescriptionLaden",
  "fileCreator", "fileCreatorContent", "fileCreatorEmpty",
  "fileCreatorLaden", "fileLicence", "fileLicenceContent",
  "fileLicenceEmpty", "fileLicenceLaden", "osglIntArrayData",
  "osglIntVectorElArray", "osglIntVectorEl", "osglIntVectorElStart",
  "osglIntVectorElAttributes", "osglIntVectorElAttList",
  "osglIntVectorElAtt", "osglIntVectorElContent", "osglIntVectorBase64",
  "Base64SizeAttribute", "Base64Content", "Base64Empty", "Base64Laden",
  "osglIncrAttribute", "osglMultAttribute", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,    32,     9,    13,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   365,   366,   366,   367,   368,   369,   369,   370,   370,
     371,   372,   373,   374,   374,   375,   376,   376,   377,   377,
     378,   379,   379,   380,   380,   381,   382,   383,   383,   384,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   384,
     385,   386,   387,   387,   388,   388,   389,   390,   391,   392,
     393,   393,   394,   394,   395,   396,   397,   398,   399,   399,
     400,   400,   401,   402,   403,   404,   405,   405,   406,   407,
     407,   408,   408,   409,   410,   411,   412,   413,   413,   414,
     414,   415,   416,   417,   418,   419,   419,   420,   420,   421,
     422,   423,   424,   425,   425,   426,   426,   427,   428,   429,
     430,   431,   431,   432,   432,   433,   434,   435,   436,   437,
     437,   438,   438,   439,   440,   441,   442,   443,   443,   444,
     445,   445,   446,   446,   447,   448,   449,   450,   451,   452,
     452,   453,   453,   454,   455,   456,   456,   457,   458,   459,
     460,   460,   461,   461,   461,   462,   462,   463,   463,   464,
     465,   465,   466,   466,   467,   468,   469,   469,   470,   470,
     470,   470,   470,   471,   472,   473,   474,   474,   475,   475,
     476,   477,   478,   479,   480,   481,   481,   482,   482,   483,
     484,   485,   486,   487,   488,   488,   489,   489,   490,   491,
     492,   493,   494,   494,   495,   496,   497,   498,   499,   500,
     500,   501,   501,   502,   503,   504,   504,   505,   506,   507,
     508,   508,   509,   509,   509,   510,   510,   511,   511,   512,
     513,   513,   514,   514,   515,   516,   517,   517,   518,   518,
     519,   520,   521,   521,   522,   522,   523,   524,   525,   526,
     527,   528,   528,   529,   529,   530,   531,   532,   532,   533,
     534,   535,   536,   536,   537,   537,   537,   538,   538,   539,
     539,   540,   541,   541,   542,   542,   543,   544,   545,   545,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   547,   548,   549,   549,   550,
     550,   551,   551,   552,   553,   554,   555,   556,   557,   557,
     558,   558,   559,   560,   561,   562,   563,   564,   564,   565,
     565,   566,   567,   567,   568,   569,   570,   571,   571,   572,
     572,   573,   574,   575,   576,   576,   577,   577,   578,   579,
     580,   581,   581,   582,   582,   583,   584,   585,   586,   586,
     587,   587,   588,   589,   590,   591,   592,   592,   593,   593,
     594,   595,   595,   596,   597,   598,   599,   600,   600,   601,
     601,   602,   603,   603,   604,   605,   606,   607,   608,   608,
     609,   609,   610,   611,   611,   612,   613,   614,   615,   616,
     616,   617,   617,   618,   619,   619,   620,   621,   622,   623,
     624,   624,   625,   625,   626,   627,   628,   629,   630,   630,
     631,   631,   632,   633,   634,   635,   636,   636,   637,   637,
     638,   639,   639,   640,   641,   642,   643,   644,   644,   645,
     645,   646,   647,   648,   648,   649,   650,   651,   652,   652,
     653,   653,   653,   654,   654,   655,   655,   656,   657,   658,
     658,   659,   659,   659,   660,   660,   661,   662,   663,   664,
     664,   665,   666,   667,   667,   668,   668,   669,   670,   671,
     672,   672,   673,   674,   675,   675,   676,   676,   677,   678,
     679,   679,   680,   681,   682,   683,   683,   684,   684,   684,
     685,   685,   686,   686,   687,   688,   689,   689,   690,   690,
     691,   692,   693,   693,   694,   695,   696,   697,   697,   698,
     698,   698,   699,   699,   700,   700,   701,   702,   702,   703,
     704,   705,   706,   706,   707,   708,   709,   709,   710,   711,
     712,   713,   713,   714,   715,   716,   716,   717,   718,   719,
     720,   720,   721,   722,   723,   723,   724,   725,   726,   727,
     727,   728,   729,   730,   730,   731,   732,   733,   734,   734,
     735,   736,   737,   737,   738,   739,   740,   741,   741,   742,
     743,   744,   744,   745,   746,   747,   748,   748,   749,   750,
     751,   751,   752,   753,   754,   755,   755,   756,   757,   758,
     758,   759,   759,   760,   761,   762,   762,   763,   764,   765,
     766,   766,   767,   767,   767,   768,   768,   769,   769,   770,
     771,   772,   772,   773,   773,   774,   775,   775,   776,   777,
     778,   779,   779,   780,   780,   780,   781,   781,   782,   782,
     783,   784,   784,   785,   786,   787,   788,   788,   789,   789,
     789,   789,   789,   789,   789,   789,   789,   789,   790,   790,
     791,   791,   792,   793,   793,   794,   794,   795,   796,   797,
     798,   798,   799,   799,   799,   799,   799,   800,   801,   801,
     802,   802,   803,   804,   805,   805,   806,   806,   807,   808,
     809,   810,   810,   811,   812,   813,   813,   814,   814,   815,
     816,   817,   817,   818,   819,   820,   821,   821,   822,   822,
     822,   823,   823,   824,   824,   825,   826,   827,   827,   828,
     828,   829,   830,   831,   831,   832,   833,   834,   835,   835,
     836,   836,   836,   836,   837,   837,   838,   838,   839,   840,
     840,   841,   842,   843,   844,   844,   845,   846,   847,   847,
     848,   849,   850,   851,   851,   852,   853,   854,   854,   855,
     856,   857,   858,   858,   859,   860,   861,   861,   862,   863,
     864,   865,   865,   866,   867,   868,   868,   869,   870,   871,
     872,   872,   873,   874,   875,   875,   876,   877,   878,   879,
     879,   880,   881,   882,   882,   883,   884,   885,   886,   886,
     887,   888,   889,   889,   890,   891,   892,   893,   893,   894,
     895,   896,   897,   897,   898,   898,   898,   898,   898,   898,
     898,   898,   898,   898,   899,   899,   900,   900,   901,   902,
     902,   903,   903,   904,   905,   906,   907,   907,   908,   908,
     908,   908,   908,   909,   910,   910,   911,   911,   912,   913,
     914,   914,   915,   915,   916,   917,   918,   919,   919,   920,
     921,   922,   922,   923,   923,   924,   925,   926,   926,   927,
     928,   929,   930,   930,   931,   931,   931,   932,   932,   933,
     933,   934,   935,   936,   936,   937,   937,   938,   939,   940,
     940,   941,   942,   943,   944,   944,   945,   945,   945,   945,
     946,   946,   947,   947,   948,   949,   949,   950,   951,   952,
     953,   953,   954,   955,   956,   956,   957,   958,   959,   960,
     960,   961,   962,   963,   963,   964,   965,   966,   967,   967,
     968,   969,   970,   970,   971,   972,   973,   974,   974,   975,
     976,   977,   977,   978,   979,   980,   981,   981,   982,   983,
     984,   984,   985,   986,   987,   988,   988,   989,   990,   991,
     991,   992,   993,   994,   995,   995,   996,   997,   998,   998,
     999,  1000,  1001,  1002,  1002,  1003,  1004,  1005,  1006,  1006,
    1007,  1007,  1007,  1007,  1007,  1007,  1007,  1007,  1007,  1007,
    1008,  1008,  1009,  1009,  1010,  1011,  1011,  1012,  1012,  1013,
    1014,  1015,  1016,  1016,  1017,  1017,  1017,  1017,  1017,  1018,
    1019,  1019,  1020,  1020,  1021,  1022,  1023,  1023,  1024,  1025,
    1026,  1026,  1027,  1028,  1029,  1030,  1030,  1031,  1031,  1031,
    1031,  1031,  1031,  1031,  1032,  1032,  1033,  1033,  1034,  1035,
    1036,  1036,  1037,  1038,  1038,  1039,  1039,  1040,  1041,  1042,
    1042,  1043,  1044,  1045,  1046,  1047,  1047,  1048,  1048,  1048,
    1049,  1050,  1051,  1052,  1052,  1053,  1054,  1054,  1055,  1056,
    1057,  1058,  1058,  1059,  1060,  1061,  1062,  1062,  1063,  1064,
    1065,  1066,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,
    1074,  1075,  1075,  1076,  1077,  1078,  1079,  1079,  1080,  1081,
    1082,  1083,  1083,  1084,  1085,  1086,  1087,  1087,  1088,  1089,
    1090,  1091,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,
    1098,  1099,  1100,  1101,  1102,  1102,  1103,  1104,  1105,  1106,
    1106,  1107,  1108,  1109,  1110,  1110,  1111,  1112,  1113,  1114,
    1114,  1115,  1116,  1117,  1118,  1118,  1119,  1120,  1121,  1122,
    1123,  1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1137,  1138,  1139,  1139,  1140,  1141,
    1142,  1143,  1143,  1144,  1144,  1144,  1145,  1145,  1146,  1147,
    1148,  1149,  1149,  1150,  1151,  1151,  1152,  1152,  1152,  1152,
    1153,  1154,  1155,  1155,  1156,  1156,  1157,  1158,  1159,  1159,
    1160,  1160,  1160,  1160,  1160,  1161,  1161,  1162,  1162,  1163,
    1163,  1164,  1165,  1165,  1166,  1166,  1167,  1167,  1168,  1169,
    1169,  1170,  1170,  1171,  1171,  1172,  1173,  1173,  1174,  1174,
    1175,  1175,  1176,  1177,  1177,  1178,  1178,  1179,  1179,  1180,
    1181,  1181,  1182,  1182,  1183,  1184,  1185,  1186,  1186,  1187,
    1187,  1188,  1189,  1190,  1191,  1191,  1192,  1192,  1193,  1194,
    1195,  1190,  1191,  1191,  1192,  1192,  1193
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     1,     1,     0,     6,     0,     1,     0,     2,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     3,     1,     0,     1,     3,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     3,     1,     0,     1,     3,
       1,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     3,     1,     1,     0,     2,     1,     1,
       3,     1,     3,     1,     1,     0,     2,     1,     1,     3,
       1,     3,     1,     1,     0,     2,     1,     1,     3,     1,
       3,     1,     0,     1,     3,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     2,     1,     0,
       2,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     2,     4,     3,     1,     1,     1,     2,
       1,     3,     3,     1,     1,     1,     2,     1,     3,     3,
       1,     1,     1,     2,     1,     3,     3,     1,     1,     1,
       2,     1,     3,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     3,     1,     1,     1,     1,
       2,     1,     3,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     2,     4,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     3,     4,     0,
       3,     1,     1,     0,     1,     1,     1,     1,     3,     6,
       0,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       2,     1,     0,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     2,     1,     0,     2,     1,     1,     1,     1,
       3,     7,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     3,     1,
       4,     1,     1,     2,     1,     3,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     2,     1,
       3,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       0,     3,     1,     1,     0,     1,     1,     1,     1,     3,
       4,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     2,     1,     0,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     2,     1,     0,     2,     1,     1,
       1,     1,     3,     7,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     0,     3,     1,     1,
       0,     1,     1,     1,     1,     3,     4,     0,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     2,     1,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       2,     1,     0,     2,     1,     1,     1,     1,     3,     7,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       2,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       0,     2,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       2,     4,     3,     1,     1,     0,     2,     1,     1,     1,
       3,     3,     3,     2,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     4,     1,     1,     4,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     4,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     4,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     2,     0,     2,     1,     1,     1,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     1,
       1,     1,     3,     0,     1,     1,     1,     1,     1,     3,
       1,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     3,     3,     4,     1,     1,     2,     1,     3,     4,
       4,     4,     1,     1,     2,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    16,     6,     1,  1171,    14,    18,
      17,     0,     7,     0,    13,     2,    12,    20,   147,     0,
       0,  1175,  1170,  1172,  1173,    16,    10,     3,     8,     9,
     149,   217,     0,     0,    24,    19,    21,    22,  1174,     0,
    1190,  1189,     0,  1197,  1196,     0,  1204,  1203,     0,  1211,
    1210,     0,  1218,  1217,     0,  1177,  1178,  1180,  1186,  1187,
    1188,  1181,  1193,  1194,  1195,  1182,  1200,  1201,  1202,  1183,
    1207,  1208,  1209,  1184,  1214,  1215,  1216,    14,   219,   259,
       0,     0,   153,   148,   150,   151,    23,    41,    49,    57,
      65,    76,    84,    92,   100,   108,   116,   127,     0,    26,
      27,    29,     0,    30,     0,    31,     0,    32,    66,    33,
       0,    34,     0,    35,     0,    36,     0,    37,     0,    38,
     117,    39,     0,     0,     0,     0,     0,     0,  1176,  1179,
      11,   261,   435,     0,     0,   223,   218,   220,   221,   152,
     197,   164,   173,   182,   191,     0,   155,   156,   158,   166,
     159,   175,   160,   184,   161,   192,   162,     0,    25,    28,
       0,    45,    40,    42,    43,     0,    53,    48,    50,    51,
       0,    61,    56,    58,    59,     0,     0,    67,     0,    80,
      75,    77,    78,     0,    88,    83,    85,    86,     0,    96,
      91,    93,    94,     0,   104,    99,   101,   102,     0,   112,
     107,   109,   110,     0,     0,   118,  1164,     0,   128,  1191,
    1198,  1205,  1212,  1219,   437,    15,   439,     0,   265,   260,
     262,   263,   222,   239,   231,     0,   225,   226,   228,     0,
     229,     0,   154,   157,     0,   165,     0,   174,     0,   183,
       0,  1058,     0,   193,  1055,  1056,  1057,     0,   198,    47,
      44,     0,    55,    52,     0,    63,    60,     0,     0,     0,
      72,    64,    69,    70,    82,    79,     0,    90,    87,     0,
      98,    95,     0,   106,   103,     0,   114,   111,     0,     0,
       0,   123,   115,   120,   121,     0,     0,     0,   132,   126,
     129,   130,     0,   438,   264,   415,   286,   297,   305,   316,
     323,   330,   337,   396,   388,   344,   355,   377,   366,   404,
       0,   267,   268,   270,   287,   271,     0,   272,     0,   273,
       0,   274,     0,   275,     0,   276,     0,   277,     0,   278,
       0,   280,     0,   279,     0,   281,     0,   282,     0,   283,
       0,   284,     0,   224,   227,     0,   235,   230,   232,   233,
       0,   240,     0,   163,     0,  1116,   167,   169,   168,  1113,
    1114,  1115,     0,   172,   176,   178,   177,     0,   181,   185,
     187,   186,  1164,     0,   190,     0,   202,   196,   199,   200,
      46,    54,    62,    68,    74,    71,     0,    81,    89,    97,
     105,   113,   119,   125,   122,     0,  1164,  1163,  1166,  1167,
    1168,  1169,  1165,   131,   138,     0,   134,   135,   140,   449,
     446,   436,   444,   445,  1164,  1164,  1164,   440,   442,   443,
     441,   266,   269,     0,   288,     0,   301,   296,   298,   299,
       0,     0,   306,     0,     0,     0,     0,     0,     0,     0,
     345,     0,   356,     0,   367,     0,   378,     0,   389,     0,
     397,     0,     0,   405,     0,   416,   237,   234,     0,     0,
     244,   238,   241,   242,  1161,  1162,     0,   171,     0,     0,
     180,     0,   189,  1059,   195,     0,   201,   208,     0,   204,
     205,   210,    73,   124,  1138,   133,   136,     0,   139,   451,
       0,   660,   453,     0,     0,     0,     0,   292,   285,   289,
     290,   303,   300,     0,     0,     0,   310,   304,   307,   308,
       0,     0,   320,   315,   317,   318,     0,   327,   322,   324,
     325,     0,   334,   329,   331,   332,     0,   341,   336,   338,
     339,     0,     0,   349,   343,   346,   347,     0,   360,   354,
     357,   358,     0,   371,   365,   368,   369,     0,   382,   376,
     379,   380,     0,   393,   387,   390,   391,     0,   401,   395,
     398,   399,     0,     0,   409,   403,   406,   407,     0,   420,
     414,   417,   418,   236,   243,   250,     0,   246,   247,   252,
     170,  1117,   179,   188,   194,   203,   206,     0,   209,     0,
     146,   137,     0,     0,  1083,  1121,   141,   144,   142,  1080,
    1081,  1082,   143,  1118,  1119,  1120,   447,   662,   826,   664,
    1164,     0,   452,   454,  1164,  1164,  1164,   291,     0,   294,
     295,   302,     0,     0,   309,     0,   312,     0,   319,     0,
       0,  1029,   326,     0,   333,     0,   340,     0,     0,  1033,
     348,     0,   351,   353,  1035,   359,     0,   362,   364,   370,
       0,   373,   375,   381,     0,   384,   386,   392,     0,   400,
       0,     0,   408,     0,     0,   411,   419,   426,     0,   422,
     423,   428,   245,   248,     0,   251,     0,   216,   207,   211,
     214,   212,   213,   145,  1164,     0,   828,   992,   830,  1164,
       0,   663,   665,     0,   460,   457,   450,   455,   456,  1145,
    1135,  1129,   293,  1133,     0,   311,   313,  1141,     0,   321,
    1030,   328,   335,   342,  1140,   350,   352,     0,  1034,   361,
     363,   372,   374,   383,   385,   394,   402,  1142,     0,   410,
     412,   421,   424,     0,   427,     0,   258,   249,   253,   256,
     254,   255,   215,  1084,  1122,   994,   448,     0,  1164,     0,
     829,   831,     0,   671,   668,   661,   666,   667,  1164,   462,
       0,   482,     0,     0,     0,     0,  1044,  1032,     0,     0,
       0,  1036,  1037,  1038,  1039,     0,     0,   434,   425,   429,
     432,   430,   431,   257,  1164,     0,   995,     0,   837,   834,
     827,   832,   833,  1164,   673,     0,   693,     0,  1139,   458,
     484,   504,     0,  1164,     0,   463,   314,  1031,  1043,     0,
       0,     0,   413,   433,     0,  1000,   998,   993,   996,   997,
    1164,   839,     0,   859,     0,  1137,   669,   695,   716,     0,
    1164,     0,   674,   506,   575,     0,     0,   485,     0,     0,
     467,   461,   464,   465,  1040,  1041,  1042,  1164,     0,  1136,
     835,   861,   882,     0,  1164,     0,   840,   718,   787,     0,
       0,   696,     0,     0,   678,   672,   675,   676,   577,   597,
       0,   512,   509,   505,   507,   508,     0,   489,   483,   486,
     487,  1164,   466,   473,     0,   469,   470,   475,  1143,   999,
    1003,  1001,     0,   884,   953,     0,     0,   862,     0,     0,
     844,   838,   841,   842,   670,   724,   721,   717,   719,   720,
       0,   700,   694,   697,   698,  1164,   677,   684,     0,   680,
     681,   686,   599,   621,     0,     0,   578,   514,     0,   521,
       0,   495,   488,     0,   491,   492,   497,  1144,   468,   471,
       0,   474,     0,     0,  1164,  1101,  1048,     0,  1093,     0,
    1004,  1005,  1010,  1045,  1046,  1047,  1012,  1007,  1009,  1090,
    1091,  1092,  1011,  1098,  1099,  1100,  1008,  1013,   836,   890,
     887,   883,   885,   886,     0,   866,   860,   863,   864,  1164,
     843,   850,     0,   846,   847,   852,   790,   788,   792,   726,
       0,   733,     0,   706,   699,     0,   702,   703,   708,  1134,
     679,   682,     0,   685,   459,     0,     0,     0,   582,   576,
     579,   580,   510,   523,   530,     0,  1164,     0,   515,   490,
     493,     0,   496,     0,   481,   472,  1164,   476,   477,  1067,
    1068,   478,   479,  1164,     0,     0,  1164,     0,  1017,  1002,
    1014,  1015,  1006,   956,   954,   958,   892,     0,   899,     0,
     872,   865,     0,   868,   869,   874,  1128,   845,   848,     0,
     851,     0,   791,   722,   735,   742,     0,     0,   727,   701,
     704,     0,   707,     0,   692,   683,   687,   688,   689,   690,
     624,   622,   626,     0,     0,   604,   598,   601,   602,   588,
     581,     0,   584,   585,   590,   532,   539,     0,     0,   524,
       0,  1222,   518,   513,   516,   517,     0,   503,   494,   498,
     499,   500,   501,   480,     0,  1049,  1102,  1164,  1094,  1016,
    1026,     0,  1025,     0,  1019,  1020,  1022,  1023,  1024,     0,
     957,   888,   901,   908,     0,     0,   893,   867,   870,     0,
     873,     0,   858,   849,   853,   854,   855,   856,     0,   807,
     789,   804,   805,  1164,     0,  1063,     0,  1088,   793,   799,
     803,   802,  1060,  1061,  1062,   796,   801,  1085,  1086,  1087,
     798,   800,   797,   795,   794,   744,   751,     0,     0,   736,
    1222,   730,   725,   728,   729,     0,   715,   705,  1073,  1106,
       0,     0,   709,   710,   712,  1070,  1071,  1072,   711,   713,
    1103,  1104,  1105,   691,     0,   625,     0,   603,   609,     0,
     606,   611,   583,   586,     0,   589,   541,   548,     0,     0,
     533,  1222,   527,   522,   525,   526,  1164,     0,     0,   520,
    1220,  1221,   502,  1164,  1132,  1028,     0,  1018,  1021,     0,
     973,   955,   970,   971,     0,  1053,   959,   965,   967,  1050,
    1051,  1052,   969,   968,   962,   964,   966,   963,   960,   961,
     910,   917,     0,     0,   902,  1222,   896,   891,   894,   895,
       0,   881,   871,  1078,  1111,  1164,  1164,   875,   876,   878,
    1075,  1076,  1077,   877,   879,  1108,  1109,  1110,   857,   806,
     814,  1149,     0,   809,   811,   816,   810,  1146,  1151,     0,
       0,     0,   753,   760,     0,     0,   745,  1222,   739,   734,
     737,   738,     0,   732,   714,  1164,  1164,     0,   641,   623,
     638,   639,     0,  1126,   627,   633,   637,   636,   630,   632,
     634,   631,   635,  1123,  1124,  1125,   629,   628,   600,   605,
     607,     0,   610,     0,   596,   587,   591,   592,   593,   594,
     550,   557,     0,     0,   542,  1222,   536,   531,   534,   535,
       0,   529,  1130,  1164,     0,   519,  1225,  1223,  1227,  1069,
    1027,   972,   980,     0,   975,   977,   982,   976,     0,   919,
     926,     0,     0,   911,  1222,   905,   900,   903,   904,     0,
     898,   880,     0,     0,   808,   812,     0,   815,  1147,     0,
    1150,  1164,  1064,  1089,   762,   769,     0,     0,   754,  1222,
     748,   743,   746,   747,     0,   741,   731,  1074,  1107,   640,
     648,     0,   643,   645,   650,   644,     0,     0,   619,   608,
     616,   617,     0,  1164,   612,   615,  1065,   613,  1095,  1096,
     614,   595,   559,   566,     0,     0,   551,  1222,   545,   540,
     543,   544,     0,   538,   528,     0,     0,  1237,  1232,  1234,
    1235,     0,  1226,   974,   978,     0,   981,  1054,   928,   935,
       0,     0,   920,  1222,   914,   909,   912,   913,     0,   907,
     897,  1164,  1164,     0,   825,   813,   823,   817,   818,   821,
     819,   822,   820,  1222,  1158,  1148,  1156,  1157,  1155,  1154,
    1153,  1152,  1131,   771,   778,     0,     0,   763,  1222,   757,
     752,   755,   756,     0,   750,   740,   642,   646,     0,   649,
    1127,   618,     0,     0,     0,   568,   511,     0,     0,   560,
    1222,   554,   549,   552,   553,     0,   547,   537,  1164,     0,
    1236,     0,  1224,  1164,  1164,  1228,  1230,  1229,     0,   991,
     979,   989,   983,   984,   987,   985,   988,   986,   937,   944,
       0,     0,   929,  1222,   923,   918,   921,   922,     0,   916,
     906,  1079,  1112,   824,     0,  1160,   780,   723,     0,     0,
     772,  1222,   766,   761,   764,   765,     0,   759,   749,     0,
     659,   647,   657,   651,   652,   655,   653,   656,   654,   620,
       0,  1164,     0,   569,  1222,   563,   558,   561,   562,     0,
     556,   546,  1233,  1238,     0,     0,     0,   990,   946,   889,
       0,     0,   938,  1222,   932,   927,   930,   931,     0,   925,
     915,  1159,     0,   781,  1222,   775,   770,   773,   774,     0,
     768,   758,   658,  1066,  1097,  1222,   572,   567,   570,   571,
       0,   565,   555,  1231,  1164,  1164,     0,   947,  1222,   941,
     936,   939,   940,     0,   934,   924,  1222,   784,   779,   782,
     783,     0,   777,   767,     0,   574,   564,  1239,  1240,  1222,
     950,   945,   948,   949,     0,   943,   933,     0,   786,   776,
     573,     0,   952,   942,   785,   951
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    27,    28,    29,    15,    16,
       8,     9,    18,    19,    35,    36,    37,    98,    99,   100,
     101,   102,   162,   163,   164,   251,   103,   104,   167,   168,
     169,   254,   105,   106,   172,   173,   174,   257,   107,   108,
     176,   177,   261,   262,   263,   386,   109,   110,   180,   181,
     182,   266,   111,   112,   185,   186,   187,   269,   113,   114,
     190,   191,   192,   272,   115,   116,   195,   196,   197,   275,
     117,   118,   200,   201,   202,   278,   119,   120,   204,   205,
     282,   283,   284,   395,   121,   122,   207,   289,   290,   291,
     405,   406,   407,   408,   487,   488,   596,   591,    31,    32,
      83,    84,    85,   145,   146,   147,   148,   149,   234,   235,
     356,   353,   466,   150,   151,   236,   237,   364,   363,   469,
     152,   153,   238,   239,   369,   368,   471,   154,   155,   242,
     374,   475,   156,   157,   247,   377,   378,   379,   478,   479,
     480,   481,   587,   588,   679,   678,    79,    80,   136,   137,
     138,   225,   226,   227,   228,   229,   347,   348,   349,   458,
     230,   231,   350,   461,   462,   463,   576,   577,   578,   579,
     674,   675,   738,   737,   132,   133,   219,   220,   221,   310,
     311,   312,   313,   314,   423,   498,   499,   500,   618,   619,
     315,   316,   427,   428,   429,   503,   317,   318,   431,   507,
     508,   509,   625,   626,   319,   320,   513,   514,   515,   321,
     322,   518,   519,   520,   323,   324,   523,   524,   525,   325,
     326,   528,   529,   530,   327,   328,   439,   534,   535,   536,
     641,   642,   329,   330,   441,   539,   540,   541,   646,   647,
     331,   332,   443,   544,   545,   546,   650,   651,   333,   334,
     445,   549,   550,   551,   654,   655,   335,   336,   447,   554,
     555,   556,   337,   338,   449,   559,   560,   561,   339,   340,
     452,   565,   566,   567,   664,   665,   341,   342,   454,   570,
     571,   572,   668,   669,   670,   671,   733,   734,   779,   778,
     215,   216,   292,   293,   417,   411,   412,   413,   490,   491,
     492,   611,   612,   696,   697,   698,   760,   761,   762,   804,
     841,   842,   843,   884,   885,   886,   887,   940,   941,  1027,
    1025,   801,   802,   836,   878,   879,   880,   933,   934,   935,
     936,  1021,  1022,  1109,  1108,   834,   835,   873,   874,   875,
     928,   929,   930,  1017,  1103,  1104,  1105,  1228,  1014,  1015,
    1098,  1223,  1224,  1225,  1360,  1096,  1097,  1219,  1357,  1358,
    1359,  1452,  1217,  1218,  1353,  1449,  1450,  1451,  1535,  1351,
    1352,  1445,  1532,  1533,  1534,  1609,  1443,  1444,  1528,  1606,
    1607,  1608,  1650,  1526,  1527,  1602,  1647,  1648,  1649,  1674,
     869,   870,   925,  1009,  1010,  1011,  1091,  1092,  1093,  1094,
    1214,  1215,  1346,  1345,   923,   924,  1006,  1086,  1087,  1088,
    1209,  1210,  1211,  1341,  1342,  1434,  1429,  1430,  1431,  1004,
    1081,  1082,  1204,  1205,  1324,  1319,  1320,  1321,  1421,  1422,
    1423,  1424,  1518,  1519,  1593,  1591,  1592,   608,   609,   690,
     691,   755,   756,   757,   795,   796,   797,   831,   865,   866,
     867,   918,   919,   920,   921,  1002,  1003,  1076,  1075,   828,
     829,   860,   912,   913,   914,   995,   996,   997,   998,  1071,
    1072,  1192,  1187,   858,   859,   907,   908,   909,   990,   991,
     992,  1067,  1182,  1183,  1184,  1312,  1065,  1066,  1178,  1309,
    1310,  1311,  1414,  1176,  1177,  1305,  1411,  1412,  1413,  1513,
    1303,  1304,  1407,  1510,  1511,  1512,  1586,  1405,  1406,  1506,
    1583,  1584,  1585,  1639,  1504,  1505,  1579,  1636,  1637,  1638,
    1671,  1577,  1578,  1632,  1668,  1669,  1670,  1687,   904,   987,
     988,  1061,  1062,  1158,  1150,  1151,  1152,  1292,  1293,  1294,
    1295,  1396,  1397,  1487,  1485,  1486,   687,   688,   749,   750,
     790,   791,   792,   822,   823,   824,   855,   901,   902,   903,
     982,   983,   984,   985,  1059,  1060,  1144,  1143,   852,   853,
     896,   976,   977,   978,  1052,  1053,  1054,  1055,  1139,  1140,
    1277,  1272,   894,   895,   971,   972,   973,  1047,  1048,  1049,
    1135,  1267,  1268,  1269,  1389,  1133,  1134,  1263,  1386,  1387,
    1388,  1478,  1261,  1262,  1382,  1475,  1476,  1477,  1568,  1380,
    1381,  1471,  1565,  1566,  1567,  1628,  1469,  1470,  1561,  1625,
    1626,  1627,  1663,  1559,  1560,  1621,  1660,  1661,  1662,  1684,
    1619,  1620,  1656,  1681,  1682,  1683,  1691,   968,  1044,  1045,
    1129,  1130,  1246,  1241,  1242,  1243,  1373,  1374,  1375,  1376,
    1465,  1466,  1552,  1550,  1551,   746,   747,   785,   817,   818,
     819,   848,   891,   892,   949,   950,   951,  1039,  1040,  1041,
    1123,  1124,  1125,  1126,  1127,  1128,  1236,   630,   631,   643,
     644,   717,   718,   771,   772,   773,   774,   767,   952,   953,
     954,   955,  1248,  1249,  1250,  1251,   956,   244,   245,   246,
    1161,  1162,  1163,  1164,  1435,  1436,  1028,  1029,  1030,  1194,
    1195,  1196,  1197,  1279,  1280,  1281,  1282,   957,   599,   600,
     601,  1166,  1167,  1168,  1169,   958,   959,   960,   961,  1437,
    1438,  1439,   962,   963,   964,   965,  1199,  1200,  1201,  1202,
    1284,  1285,  1286,  1287,   358,   359,   360,   361,   966,   603,
     604,   605,  1332,  1333,  1334,  1335,   856,   418,  1018,  1173,
     967,   432,   832,   419,   751,   692,   208,   613,   440,   434,
     453,   786,   805,   420,  1296,  1297,  1298,  1399,  1400,  1501,
    1495,  1496,  1497,  1574,   467,   285,   286,   402,    10,    11,
      22,    23,    24,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,  1229,  1230,  1367,  1368,
    1461,  1462,  1545,  1542,  1231,  1364,  1458,  1459,  1460,  1546,
    1547
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1376
static const yytype_int16 yypact[] =
{
     135, -1376, -1376,    56,  -152,    48, -1376, -1376,    65,    34,
   -1376,   328, -1376,   334, -1376, -1376, -1376, -1376,    78,   360,
     480, -1376, -1376, -1376, -1376,  -152, -1376, -1376, -1376, -1376,
   -1376,   106,   370,   171, -1376, -1376, -1376, -1376, -1376,   102,
   -1376, -1376,   158, -1376, -1376,   205, -1376, -1376,   218, -1376,
   -1376,   220, -1376, -1376,    22,   337, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376,    65, -1376,   178,
     382,   -37, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,   206,   392,
   -1376, -1376,   384, -1376,   386, -1376,   388, -1376,   212, -1376,
     391, -1376,   394, -1376,   396, -1376,   400, -1376,   403, -1376,
     217, -1376,   278,    83,    81,   104,    79,    85, -1376, -1376,
   -1376, -1376,   231,   405,   -11, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376,   255,   198, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376,   140, -1376,   278, -1376, -1376,
      32, -1376, -1376, -1376, -1376,    43, -1376, -1376, -1376, -1376,
      30, -1376, -1376, -1376, -1376,   359,   408, -1376,    35, -1376,
   -1376, -1376, -1376,    28, -1376, -1376, -1376, -1376,    27, -1376,
   -1376, -1376, -1376,    26, -1376, -1376, -1376, -1376,    25, -1376,
   -1376, -1376, -1376,   372,   413, -1376, -1376,   415, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376,   146, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376,   293,    84, -1376, -1376,   419,
   -1376,   278, -1376, -1376,   410,   260,   417,   260,   423,   260,
     414, -1376,   455, -1376, -1376, -1376, -1376,   425, -1376, -1376,
   -1376,   375, -1376, -1376,   390, -1376, -1376,   398,   464,    47,
   -1376, -1376, -1376, -1376, -1376, -1376,   380, -1376, -1376,   412,
   -1376, -1376,   378, -1376, -1376,   406, -1376, -1376,   418,   472,
      17, -1376, -1376, -1376, -1376,   478,     2,   331, -1376, -1376,
   -1376, -1376,   430,   347, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
     443,   407, -1376, -1376,     8, -1376,   432, -1376,   499, -1376,
     471, -1376,   471, -1376,   471, -1376,   471, -1376,   476, -1376,
     476, -1376,   476, -1376,   476, -1376,   471, -1376,   471, -1376,
     502, -1376,   278, -1376, -1376,    24, -1376, -1376, -1376, -1376,
     434, -1376,   440, -1376,   528, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376,   440, -1376, -1376, -1376, -1376,   440, -1376, -1376,
   -1376, -1376, -1376,   527, -1376,   343, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376,   447, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376,   437, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376,   441,   446, -1376, -1376,   411,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376,   442, -1376,    16, -1376, -1376, -1376, -1376,
     543,   444, -1376,   552,   449,   453,   457,   460,   571,   488,
   -1376,   490, -1376,   492, -1376,   494, -1376,   500, -1376,   503,
   -1376,   596,   505, -1376,   513, -1376, -1376, -1376,   450,   429,
   -1376, -1376, -1376, -1376, -1376, -1376,   531, -1376,   598,   497,
   -1376,   509, -1376, -1376, -1376,   533, -1376, -1376,   554,   555,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376,   573,   124, -1376,
     587,   516,   652,   697,   701,   705,    20, -1376, -1376, -1376,
   -1376, -1376, -1376,   593,   774,   -34, -1376, -1376, -1376, -1376,
     778,   224, -1376, -1376, -1376, -1376,   462, -1376, -1376, -1376,
   -1376,   -24, -1376, -1376, -1376, -1376,    52, -1376, -1376, -1376,
   -1376,   803,    82, -1376, -1376, -1376, -1376,   -29, -1376, -1376,
   -1376, -1376,     3, -1376, -1376, -1376, -1376,   -32, -1376, -1376,
   -1376, -1376,    87, -1376, -1376, -1376, -1376,    93, -1376, -1376,
   -1376, -1376,   804,   435, -1376, -1376, -1376, -1376,   486, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376,   638,   704, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376,   584,   124,   706,
   -1376, -1376,   809,   810, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,   624,   782,
   -1376,   586, -1376, -1376, -1376, -1376, -1376, -1376,   698, -1376,
   -1376, -1376,   811,   807, -1376,   -27, -1376,   812, -1376,   813,
     226, -1376, -1376,   470, -1376,   -21, -1376,   125,   814, -1376,
   -1376,    99, -1376, -1376, -1376, -1376,    33, -1376, -1376, -1376,
      19, -1376, -1376, -1376,     6, -1376, -1376, -1376,   123, -1376,
      97,   816, -1376,   815,   451, -1376, -1376, -1376,   715,   719,
   -1376, -1376, -1376, -1376,   605,   124,   720, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376,   819, -1376,   630,   796, -1376,
     607, -1376, -1376,   824,   678, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376,   828, -1376, -1376, -1376,   830, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376,   615,   362, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,   831, -1376,
   -1376, -1376, -1376,   617,   124,   729, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376,   808, -1376,   619,
   -1376, -1376,   832,   654, -1376, -1376, -1376, -1376, -1376, -1376,
     686,   682,   805,   749,   717,   713, -1376, -1376,   841,   843,
     845, -1376, -1376, -1376, -1376,   699,   741, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376,   621, -1376,   844,   659, -1376,
   -1376, -1376, -1376, -1376, -1376,   669,   666,   818, -1376, -1376,
   -1376,   696,   805, -1376,   625, -1376, -1376, -1376, -1376,   850,
     851,   852, -1376, -1376,   856, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376,   671,   668,   825, -1376, -1376, -1376,   707,   818,
   -1376,   627, -1376, -1376,   689,   629,   637, -1376,   861,   496,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,   456, -1376,
   -1376, -1376,   709,   825, -1376,   648, -1376, -1376, -1376,   655,
     658, -1376,   863,   487, -1376, -1376, -1376, -1376, -1376,   692,
     805,   710, -1376, -1376, -1376, -1376,   197, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376,   721,   723, -1376, -1376, -1376, -1376,
   -1376, -1376,   151, -1376, -1376,   667,   677, -1376,   866,   495,
   -1376, -1376, -1376, -1376,   767,   725, -1376, -1376, -1376, -1376,
     169, -1376, -1376, -1376, -1376, -1376, -1376, -1376,   690,   688,
   -1376, -1376, -1376, -1376,   849,   681, -1376, -1376,   727,   730,
     839, -1376, -1376,   731,   733, -1376, -1376, -1376, -1376, -1376,
     683,   173,   878,   879, -1376, -1376, -1376,   880, -1376,   708,
     151, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,   780,   735,
   -1376, -1376, -1376, -1376,   174, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376,   691,   700, -1376, -1376, -1376, -1376, -1376, -1376,
     734,   739,   839, -1376, -1376,   694,   737, -1376, -1376, -1376,
   -1376, -1376,   712,   173,   786,   884,   714,   -96, -1376, -1376,
   -1376, -1376, -1376, -1376,   745,   839, -1376,   716, -1376, -1376,
   -1376,   718,   173,   743, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376,   886,   893, -1376,   122, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376,   747,   751,   839,
   -1376, -1376,   702,   746, -1376, -1376, -1376, -1376, -1376,   722,
     173,   724,   291, -1376, -1376,   755,   839,   726, -1376, -1376,
   -1376,   728,   326,   757, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376,   896,   560, -1376, -1376, -1376, -1376, -1376,
   -1376,   753,   765, -1376, -1376, -1376,   759,   839,   732, -1376,
     899,   761, -1376, -1376, -1376, -1376,   763, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376,   901, -1376, -1376, -1376, -1376, -1376,
   -1376,   881, -1376,   769,   117, -1376, -1376, -1376, -1376,   736,
     564, -1376, -1376,   770,   839,   738, -1376, -1376, -1376,   740,
     137,   771, -1376, -1376, -1376, -1376, -1376, -1376,   -75, -1376,
   -1376, -1376, -1376, -1376,   908, -1376,   911, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376,   773,   839,   742, -1376,
     761, -1376, -1376, -1376, -1376,   775, -1376, -1376, -1376, -1376,
     912,   914, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376,   744,   626,   915, -1376, -1376,   576,
   -1376, -1376, -1376, -1376,   748,   173, -1376,   776,   839,   750,
   -1376,   761, -1376, -1376, -1376, -1376, -1376,   784,   788, -1376,
     711, -1376, -1376, -1376, -1376, -1376,   792, -1376, -1376,   -73,
   -1376, -1376, -1376, -1376,   916, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376,   790,   839,   752, -1376,   761, -1376, -1376, -1376, -1376,
     794, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376,   821,   798, -1376, -1376,   799, -1376, -1376,   920,
     919,   922, -1376,   800,   839,   754, -1376,   761, -1376, -1376,
   -1376, -1376,   801, -1376, -1376, -1376, -1376,   -62, -1376, -1376,
   -1376, -1376,   929, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376,   756,    74,   802, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376,   806,   839,   758, -1376,   761, -1376, -1376, -1376, -1376,
     820, -1376, -1376, -1376,   760, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376,   826,   817, -1376, -1376,   799,   925, -1376,
     822,   839,   762, -1376,   761, -1376, -1376, -1376, -1376,   823,
   -1376, -1376,   440,   440, -1376, -1376,   764,   236, -1376,   766,
     114, -1376, -1376, -1376, -1376,   827,   839,   768, -1376,   761,
   -1376, -1376, -1376, -1376,   833, -1376, -1376, -1376, -1376, -1376,
   -1376,   829,   835, -1376, -1376,   799,   928,  -105, -1376, -1376,
   -1376, -1376,   930, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376,   834,   839,   772, -1376,   761, -1376, -1376,
   -1376, -1376,   837, -1376, -1376,   933,     9, -1376, -1376, -1376,
   -1376,   936,   574, -1376, -1376,   777,   236, -1376, -1376,   836,
     839,   779, -1376,   761, -1376, -1376, -1376, -1376,   838, -1376,
   -1376, -1376, -1376,   840, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376,   761, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376,   842,   839,   781, -1376,   761, -1376,
   -1376, -1376, -1376,   847, -1376, -1376, -1376, -1376,   783,   236,
   -1376, -1376,  -103,   440,   934, -1376, -1376,   839,   785, -1376,
     761, -1376, -1376, -1376, -1376,   846, -1376, -1376, -1376,   848,
   -1376,   941, -1376, -1376, -1376, -1376, -1376, -1376,   853, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,   855,
     839,   787, -1376,   761, -1376, -1376, -1376, -1376,   854, -1376,
   -1376, -1376, -1376, -1376,   858, -1376, -1376, -1376,   839,   789,
   -1376,   761, -1376, -1376, -1376, -1376,   857, -1376, -1376,   860,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
     940, -1376,   791, -1376,   761, -1376, -1376, -1376, -1376,   862,
   -1376, -1376, -1376, -1376,   859,   944,   945, -1376, -1376, -1376,
     839,   793, -1376,   761, -1376, -1376, -1376, -1376,   867, -1376,
   -1376, -1376,   795, -1376,   761, -1376, -1376, -1376, -1376,   864,
   -1376, -1376, -1376, -1376, -1376,   761, -1376, -1376, -1376, -1376,
     868, -1376, -1376, -1376, -1376, -1376,   797, -1376,   761, -1376,
   -1376, -1376, -1376,   865, -1376, -1376,   761, -1376, -1376, -1376,
   -1376,   869, -1376, -1376,   870, -1376, -1376, -1376, -1376,   761,
   -1376, -1376, -1376, -1376,   871, -1376, -1376,   872, -1376, -1376,
   -1376,   874, -1376, -1376, -1376, -1376
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,   876, -1376,
     931, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,   873,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376,   548, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376,   875, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
     479, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376,   877, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,   385, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376,   644, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376,   332, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376,   320, -1376, -1376, -1376, -1376, -1376, -1376, -1376,   318,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376,   316, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376,   314, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376,   305, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376,   306, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376,    89, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,    44,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376,  -448, -1083, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376,  -229, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
    -439, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376,    67, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376,   -12, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,  -304,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376,    10, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376,   -59, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,  -378, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376,    50, -1376, -1376, -1376,
   -1376, -1376,  -120, -1376, -1376, -1376, -1376,  -456,  -464,  -497,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1046, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376,  -154, -1376, -1376, -1376,
   -1082, -1376, -1376, -1376, -1376, -1376,  -997, -1376, -1376, -1375,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376,  -485, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1044, -1376, -1376, -1376, -1376,
   -1376, -1376, -1043, -1376, -1376, -1376, -1374, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376,  -182, -1376, -1376, -1376,  -484, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376,  -842, -1376,  -978, -1072,
   -1376, -1376,  -817, -1376, -1376, -1376,  -142, -1376,   -77,   -90,
   -1376, -1376,  -797, -1376, -1201, -1279, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376,  -360,  -372, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376,   950, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1172, -1376, -1376, -1376,
   -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376, -1376,
   -1376
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     473,   243,   470,   598,   602,   837,  1077,   472,  1313,  1213,
     397,   897,   861,  1539,  1068,   248,  1159,  1398,  1170,  1171,
     501,   393,  1489,  1491,   484,  1110,   464,   465,   456,   276,
     273,   270,   267,  1289,   255,  1371,   249,  1099,  1377,   264,
     648,   139,   493,   494,   495,   652,  1419,   252,  1253,  1361,
     656,   384,  1089,   354,  1089,   366,     6,   371,  1259,   623,
     633,  1089,    12,  1145,     7,   635,   623,   355,   140,   222,
     637,  1136,   141,   926,   142,  1193,   143,  1521,   144,  1599,
      14,   357,  1090,   365,  1247,   370,  1255,  1256,  1179,   351,
     624,  1554,  1556,  1390,   223,  1420,   658,   705,  1398,   639,
    1432,   660,   639,   681,   682,   629,   224,   123,   629,    17,
     634,   803,  1290,   712,   653,   645,  1425,  1433,   250,  1220,
     256,   394,  1372,  1327,   268,   271,   274,   277,  1291,   265,
    1291,   253,   424,  1336,   639,  1415,   620,   639,   502,   385,
     617,  1291,   457,  1278,  1595,  1597,  1398,     1,     2,   648,
     639,   649,   723,   652,  1016,    30,  1264,   656,   593,  1325,
     240,  1329,  1330,   124,   639,   592,   710,   721,   593,   710,
     240,   710,   241,   710,   595,   942,   943,   719,   592,  1026,
     594,   629,   241,  1453,   595,    78,   240,   944,   636,   223,
     740,   741,   592,   594,   710,   593,   710,   240,   241,  1306,
     455,   224,  1273,  1274,  1275,  1276,   945,   594,   946,   241,
     125,   595,  1479,   639,   592,  1026,   629,   593,  1347,  1540,
     947,   948,   629,   126,   640,   127,   629,   657,   294,   594,
     639,   659,   435,   595,   436,   726,   437,  1514,   693,   128,
    1354,   715,   699,   700,   701,  1174,   448,    86,   450,   781,
     782,   295,   629,   442,   629,   444,    87,   446,    88,   131,
      89,   713,    90,   725,    91,   296,    92,   297,    93,   298,
      94,   299,    95,   300,    96,  1536,    97,   592,  1026,   301,
     593,   302,   158,   303,  1383,   304,   175,   305,  1258,   306,
     203,   307,   594,   308,   206,   309,   595,  1188,  1189,  1190,
    1191,  1569,   209,   140,   210,   354,   240,   141,  1153,   142,
     212,   143,   743,   144,   214,   942,   943,   752,   241,   355,
     213,  1575,  1120,  1121,  1119,  1122,  1408,  1120,  1121,   830,
    1122,   211,   592,   232,   597,   593,  1587,   240,    20,    21,
    1154,  1155,  1156,  1157,    25,    26,   945,   594,   946,   241,
     628,   595,   709,   629,   931,   629,   993,   932,  1610,   994,
     947,   948,   258,   398,   399,   400,   401,   592,  1026,  1050,
      33,    34,  1051,   343,  1446,   279,   787,   414,   415,   416,
      81,    82,   594,   768,   769,   770,   798,  1188,  1189,  1190,
    1191,  1629,   134,   135,   160,   161,   165,   166,   170,   171,
    1488,   178,   179,  1472,   183,   184,   188,   189,  1337,  1640,
     193,   194,   814,   198,   199,   217,   218,   372,   259,   260,
     352,   825,  1500,   280,   281,   287,   288,   362,  1507,   345,
     346,   838,  1651,   367,   680,   375,   376,   403,   404,  1213,
     409,   410,   425,   426,   459,   460,   464,   465,   849,   476,
     477,  1664,   496,   497,   505,   506,  1031,  1032,   862,   511,
     512,   380,  1672,   516,   517,   373,  1529,   521,   522,  1553,
     526,   527,   383,  1675,   387,   888,   389,    87,   381,    88,
     392,    89,   898,    90,   396,    91,  1685,    92,   382,    93,
     433,    94,  1562,    95,  1688,    96,   438,    97,   532,   533,
     537,   538,   542,   543,   547,   548,   390,  1692,   388,   937,
     552,   553,   295,   557,   558,   563,   564,   430,  1078,  1079,
     391,   739,  1594,   568,   569,   421,   296,  1580,   297,   451,
     298,   468,   299,   474,   300,   574,   575,  1111,  1112,   482,
     301,   483,   302,   999,   303,  1440,   304,   485,   305,  1603,
     306,   504,   307,   404,   308,    39,   309,    40,    41,    42,
     510,    43,    44,    45,   489,    46,    47,    48,   573,    49,
      50,    51,  1035,    52,    53,  1146,  1147,  1165,  1172,   531,
     780,  1153,  1622,   589,   590,   662,   663,  1198,   942,   943,
     632,   629,   666,   667,   676,   677,   694,   695,   711,   629,
    1633,   729,   663,   854,   562,   592,   581,  1056,   593,   582,
     240,  1244,  1245,  1154,  1155,   735,   736,   753,   754,   945,
     594,   946,   241,   583,   595,   765,   766,   776,   777,   788,
     789,   815,   816,   947,   948,   839,   840,   863,   864,   871,
     872,   580,  1657,  1153,  1100,  1254,  1257,   876,   877,   584,
     942,   943,   882,   883,  1114,  1283,   889,   890,   899,   900,
     585,  1115,   477,   803,  1118,   905,   906,   592,   910,   911,
     593,   606,   240,   916,   917,  1154,  1155,   969,   970,  1322,
    1323,   945,   594,   946,   241,   610,   595,   974,   975,   980,
     981,  1007,  1008,  1023,  1024,   947,   948,    38,    39,   607,
      40,    41,    42,   614,    43,    44,    45,   615,    46,    47,
      48,   616,    49,    50,    51,   621,    52,    53,  1037,  1038,
    1328,  1331,  1073,  1074,  1084,  1085,  1101,  1102,  1106,  1107,
    1348,  1349,  1141,  1142,  1148,  1149,  1180,  1181,  1185,  1186,
    1207,  1208,  1221,  1222,   672,  1234,  1239,  1240,  1265,  1266,
    1270,  1271,  1307,  1308,  1317,  1318,  1339,  1208,  1343,  1344,
    1355,  1356,  1384,  1385,  1409,  1410,  1427,  1428,  1447,  1448,
    1456,  1457,  1473,  1474,  1483,  1484,  1493,  1494,  1508,  1509,
     622,  1299,  1530,  1531,   627,  1543,  1544,  1548,  1549,  1563,
    1564,  1581,  1582,  1589,  1590,  1604,  1605,  1623,  1624,  1634,
    1635,  1645,  1646,  1658,  1659,  1666,  1667,  1679,  1680,   638,
     661,   575,   684,   685,   683,   686,   689,   704,   702,   703,
     707,   731,   714,   708,   727,   728,   667,   744,   742,   745,
     758,   748,   763,   759,   764,   775,   784,   783,   793,   794,
     799,   800,   803,   806,   809,   808,   810,   807,   811,   813,
     820,   812,   821,   826,  1362,   827,   830,   833,   844,   845,
     846,  1369,   847,   850,   854,   851,   868,   881,   857,   915,
     893,   922,   979,   927,   986,   917,  1000,   938,  1005,  1016,
     883,  1033,  1034,  1036,  1069,  1057,  1235,  1043,   989,  1012,
     931,  1019,  1083,  1080,  1116,   981,  1063,  1013,  1046,  1117,
    1137,  1113,  1206,  1392,  1393,  1226,  1064,  1233,  1160,  1131,
    1095,  1300,  1490,  1492,  1301,  1315,  1499,  1316,  1132,  1378,
    1175,  1232,  1089,  1338,   993,  1366,  1401,  1402,  1216,  1394,
    1403,  1212,  1426,  1467,  1463,  1260,  1520,  1516,  1523,  1538,
    1601,  1050,  1302,  1417,  1418,  1203,  1541,  1614,  1643,  1350,
    1654,  1655,  1365,   130,   486,   422,    77,   706,   586,  1379,
    1441,   716,   673,  1314,   720,  1416,   722,  1288,   724,   730,
    1227,  1237,   159,  1404,   939,   732,  1252,  1442,  1020,  1522,
    1340,  1555,  1557,  1517,  1070,  1290,  1001,  1480,  1454,  1395,
    1391,  1455,  1420,  1058,  1138,  1468,  1464,  1363,  1503,  1370,
    1042,  1515,  1291,  1537,  1238,   129,  1570,  1558,     0,  1525,
       0,     0,  1372,  1588,     0,     0,  1611,  1576,  1642,     0,
    1630,   233,     0,     0,     0,     0,     0,  1641,  1573,  1502,
    1618,     0,  1481,  1482,  1596,  1598,  1652,  1665,  1673,  1686,
    1676,  1689,     0,  1693,     0,     0,  1690,     0,  1694,  1617,
    1695,  1326,     0,     0,     0,     0,     0,     0,  1613,     0,
       0,  1524,  1631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1653,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   344,     0,     0,     0,     0,     0,  1571,
    1572,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1600,     0,     0,  1612,     0,     0,     0,
       0,  1615,  1616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1644,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1498,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1677,  1678
};

static const yytype_int16 yycheck[] =
{
     372,   155,   362,   488,   488,   802,  1003,   367,  1180,  1092,
       8,   853,   829,     4,   992,   157,  1062,  1296,  1062,  1062,
       4,     4,  1397,  1397,   396,  1022,     6,     7,     4,     4,
       4,     4,     4,   108,     4,   108,     4,  1015,  1239,     4,
     537,    78,   414,   415,   416,   542,   108,     4,  1130,  1221,
     547,     4,   157,    45,   157,   237,     0,   239,  1130,    93,
     516,   157,    14,  1060,   216,   521,    93,    59,   105,    80,
     526,  1049,   109,   870,   111,  1072,   113,   182,   115,   182,
      15,   235,   178,   237,  1130,   239,  1130,  1130,  1066,   231,
     124,  1466,  1466,  1265,   105,   157,   552,   124,  1377,   131,
      26,   557,   131,   588,   588,   129,   117,     5,   129,    75,
     134,    37,   187,   134,   146,   144,  1317,    43,    86,  1097,
      90,   104,   195,  1205,    96,    98,   100,   102,   203,    94,
     203,    88,   314,  1205,   131,  1307,   496,   131,   122,    92,
     120,   203,   118,  1140,  1519,  1519,  1425,    12,    13,   646,
     131,   148,   146,   650,    40,    77,  1134,   654,    44,  1205,
      46,  1205,  1205,     5,   131,    41,   630,   148,    44,   633,
      46,   635,    58,   637,    60,    24,    25,   144,    41,    42,
      56,   129,    58,  1355,    60,    79,    46,    36,   136,   105,
     675,   675,    41,    56,   658,    44,   660,    46,    58,  1177,
     342,   117,    65,    66,    67,    68,    55,    56,    57,    58,
       5,    60,  1384,   131,    41,    42,   129,    44,  1215,   210,
      69,    70,   129,     5,   142,     5,   129,   140,    82,    56,
     131,   138,   322,    60,   324,   138,   326,  1409,   610,   217,
    1218,   142,   614,   615,   616,  1062,   336,    76,   338,   734,
     734,   105,   129,   330,   129,   332,    85,   334,    87,    81,
      89,   136,    91,   140,    93,   119,    95,   121,    97,   123,
      99,   125,   101,   127,   103,  1447,   105,    41,    42,   133,
      44,   135,    76,   137,  1262,   139,    74,   141,  1130,   143,
      73,   145,    56,   147,    16,   149,    60,    61,    62,    63,
      64,  1473,   219,   105,   223,    45,    46,   109,    17,   111,
     231,   113,   684,   115,    83,    24,    25,   689,    58,    59,
     235,  1493,   205,   206,   202,   208,  1304,   205,   206,    38,
     208,   227,    41,    78,   488,    44,  1508,    46,    10,    11,
      49,    50,    51,    52,    10,    11,    55,    56,    57,    58,
     126,    60,   126,   129,   157,   129,   187,   160,  1530,   190,
      69,    70,     3,   361,   362,   363,   364,    41,    42,   195,
      10,    11,   198,    80,  1352,     3,   748,    30,    31,    32,
      10,    11,    56,    21,    22,    23,   758,    61,    62,    63,
      64,  1563,    10,    11,    10,    11,    10,    11,    10,    11,
    1397,    10,    11,  1381,    10,    11,    10,    11,  1205,  1581,
      10,    11,   784,    10,    11,    10,    11,     3,    10,    11,
      10,   793,  1400,    10,    11,    10,    11,    10,  1406,    10,
      11,   803,  1604,    10,   588,    10,    11,   106,   107,  1522,
      10,    11,    10,    11,    10,    11,     6,     7,   820,   106,
     107,  1623,    10,    11,    10,    11,   941,   941,   830,    10,
      11,    86,  1634,    10,    11,    10,  1444,    10,    11,  1466,
      10,    11,     8,  1645,    94,   847,    98,    85,    88,    87,
       8,    89,   854,    91,     6,    93,  1658,    95,    90,    97,
      19,    99,  1470,   101,  1666,   103,    20,   105,    10,    11,
      10,    11,    10,    11,    10,    11,   100,  1679,    96,   881,
      10,    11,   105,    10,    11,    10,    11,    18,  1003,  1003,
     102,   675,  1519,    10,    11,    82,   119,  1505,   121,    27,
     123,     3,   125,     6,   127,   106,   107,  1022,  1022,    92,
     133,   104,   135,   915,   137,  1342,   139,   106,   141,  1527,
     143,     8,   145,   107,   147,   218,   149,   220,   221,   222,
       8,   224,   225,   226,   153,   228,   229,   230,   118,   232,
     233,   234,   944,   236,   237,  1060,  1060,  1062,  1062,     8,
     734,    17,  1560,    10,    11,   150,   151,  1072,    24,    25,
     128,   129,   106,   107,    10,    11,    10,    11,   128,   129,
    1578,   150,   151,    39,     8,    41,     8,   979,    44,   112,
      46,    47,    48,    49,    50,    10,    11,    10,    11,    55,
      56,    57,    58,   114,    60,    10,    11,    10,    11,    10,
      11,    10,    11,    69,    70,    10,    11,    10,    11,    10,
      11,   110,  1620,    17,  1016,  1130,  1130,    10,    11,   116,
      24,    25,   156,   157,  1026,  1140,   200,   201,    10,    11,
     106,  1033,   107,    37,  1036,    10,    11,    41,    10,    11,
      44,    84,    46,   186,   187,    49,    50,    10,    11,    53,
      54,    55,    56,    57,    58,    33,    60,    10,    11,   194,
     195,    10,    11,    10,    11,    69,    70,   217,   218,   183,
     220,   221,   222,     6,   224,   225,   226,     6,   228,   229,
     230,     6,   232,   233,   234,   122,   236,   237,    10,    11,
    1205,  1205,    10,    11,    10,    11,    10,    11,    10,    11,
    1215,  1215,    10,    11,    10,    11,    10,    11,    10,    11,
     180,   181,    10,    11,   106,  1117,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,   180,   181,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
       6,  1153,    10,    11,     6,   211,   212,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,     6,
       6,   107,     3,     3,   108,   191,    34,    10,   120,     8,
       8,   106,     8,    10,     8,    10,   107,     8,   108,   199,
       6,    35,     4,   155,     4,     4,    28,   108,     6,   185,
     154,   159,    37,    94,     3,   132,     3,   130,     3,   108,
       6,   152,   193,   184,  1226,   189,    38,   161,     8,     8,
       8,  1233,     6,   192,    39,   197,   177,     6,   161,     6,
     161,   179,     6,   163,   107,   187,   186,   156,    29,    40,
     157,     3,     3,     3,   190,   194,     5,   107,   163,   162,
     157,   160,     8,   107,     8,   195,   162,   167,   163,     6,
     198,   158,     6,  1275,  1276,     6,   167,     6,  1062,   162,
     165,     3,  1397,  1397,     3,     3,  1400,     3,   167,     3,
     165,   158,   157,     8,   187,   214,     6,     8,   169,   108,
       8,   178,     3,     8,   108,   165,     8,   108,     8,     6,
       6,   195,   169,  1315,  1316,   188,    10,     6,     8,   173,
       6,     6,   164,    77,   406,   311,    25,   625,   479,   169,
     158,   641,   577,   188,   646,   164,   650,   196,   654,   664,
     209,   202,    99,   173,   885,   669,  1130,   171,   934,  1427,
    1209,  1466,  1466,  1422,   996,   187,   919,   164,   168,  1293,
     196,  1363,   157,   983,  1053,   173,  1374,   213,   171,   207,
     950,   168,   203,   166,  1124,    55,   168,   171,    -1,   175,
      -1,    -1,   195,   166,    -1,    -1,   170,   175,   158,    -1,
     166,   146,    -1,    -1,    -1,    -1,    -1,   170,   188,  1401,
     175,    -1,  1392,  1393,  1519,  1519,   174,   170,   174,   174,
     172,   172,    -1,   172,    -1,    -1,   176,    -1,   176,   196,
     176,  1205,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,
      -1,  1433,   204,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,  1481,
    1482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1523,    -1,    -1,  1538,    -1,    -1,    -1,
      -1,  1543,  1544,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1601,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1400,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1654,  1655
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   366,   367,   368,     0,   216,   375,   376,
    1153,  1154,    14,   369,    15,   373,   374,    75,   377,   378,
      10,    11,  1155,  1156,  1157,    10,    11,   370,   371,   372,
      77,   463,   464,    10,    11,   379,   380,   381,   217,   218,
     220,   221,   222,   224,   225,   226,   228,   229,   230,   232,
     233,   234,   236,   237,  1158,  1159,  1160,  1161,  1162,  1163,
    1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,
    1174,  1175,  1176,  1177,  1178,  1179,  1180,   375,    79,   511,
     512,    10,    11,   465,   466,   467,    76,    85,    87,    89,
      91,    93,    95,    97,    99,   101,   103,   105,   382,   383,
     384,   385,   386,   391,   392,   397,   398,   403,   404,   411,
     412,   417,   418,   423,   424,   429,   430,   435,   436,   441,
     442,   449,   450,     5,     5,     5,     5,     5,   217,  1160,
     373,    81,   539,   540,    10,    11,   513,   514,   515,    78,
     105,   109,   111,   113,   115,   468,   469,   470,   471,   472,
     478,   479,   485,   486,   492,   493,   497,   498,    76,   384,
      10,    11,   387,   388,   389,    10,    11,   393,   394,   395,
      10,    11,   399,   400,   401,    74,   405,   406,    10,    11,
     413,   414,   415,    10,    11,   419,   420,   421,    10,    11,
     425,   426,   427,    10,    11,   431,   432,   433,    10,    11,
     437,   438,   439,    73,   443,   444,    16,   451,  1131,   219,
     223,   227,   231,   235,    83,   655,   656,    10,    11,   541,
     542,   543,    80,   105,   117,   516,   517,   518,   519,   520,
     525,   526,    78,   470,   473,   474,   480,   481,   487,   488,
      46,    58,   494,  1061,  1062,  1063,  1064,   499,  1131,     4,
      86,   390,     4,    88,   396,     4,    90,   402,     3,    10,
      11,   407,   408,   409,     4,    94,   416,     4,    96,   422,
       4,    98,   428,     4,   100,   434,     4,   102,   440,     3,
      10,    11,   445,   446,   447,  1150,  1151,    10,    11,   452,
     453,   454,   657,   658,    82,   105,   119,   121,   123,   125,
     127,   133,   135,   137,   139,   141,   143,   145,   147,   149,
     544,   545,   546,   547,   548,   555,   556,   561,   562,   569,
     570,   574,   575,   579,   580,   584,   585,   589,   590,   597,
     598,   605,   606,   613,   614,   621,   622,   627,   628,   633,
     634,   641,   642,    80,   518,    10,    11,   521,   522,   523,
     527,  1131,    10,   476,    45,    59,   475,  1061,  1109,  1110,
    1111,  1112,    10,   483,   482,  1061,  1109,    10,   490,   489,
    1061,  1109,     3,    10,   495,    10,    11,   500,   501,   502,
      86,    88,    90,     8,     4,    92,   410,    94,    96,    98,
     100,   102,     8,     4,   104,   448,     6,     8,   361,   362,
     363,   364,  1152,   106,   107,   455,   456,   457,   458,    10,
      11,   660,   661,   662,    30,    31,    32,   659,  1122,  1128,
    1138,    82,   546,   549,  1109,    10,    11,   557,   558,   559,
      18,   563,  1126,    19,  1134,  1134,  1134,  1134,    20,   591,
    1133,   599,  1133,   607,  1133,   615,  1133,   623,  1134,   629,
    1134,    27,   635,  1135,   643,  1131,     4,   118,   524,    10,
      11,   528,   529,   530,     6,     7,   477,  1149,     3,   484,
    1149,   491,  1149,  1150,     6,   496,   106,   107,   503,   504,
     505,   506,    92,   104,  1150,   106,   457,   459,   460,   153,
     663,   664,   665,  1150,  1150,  1150,    10,    11,   550,   551,
     552,     4,   122,   560,     8,    10,    11,   564,   565,   566,
       8,    10,    11,   571,   572,   573,    10,    11,   576,   577,
     578,    10,    11,   581,   582,   583,    10,    11,   586,   587,
     588,     8,    10,    11,   592,   593,   594,    10,    11,   600,
     601,   602,    10,    11,   608,   609,   610,    10,    11,   616,
     617,   618,    10,    11,   624,   625,   626,    10,    11,   630,
     631,   632,     8,    10,    11,   636,   637,   638,    10,    11,
     644,   645,   646,   118,   106,   107,   531,   532,   533,   534,
     110,     8,   112,   114,   116,   106,   505,   507,   508,    10,
      11,   462,    41,    44,    56,    60,   461,  1061,  1082,  1083,
    1084,  1085,  1113,  1114,  1115,  1116,    84,   183,   802,   803,
      33,   666,   667,  1132,     6,     6,     6,   120,   553,   554,
    1149,   122,     6,    93,   124,   567,   568,     6,   126,   129,
    1042,  1043,   128,  1042,   134,  1042,   136,  1042,     6,   131,
     142,   595,   596,  1044,  1045,   144,   603,   604,  1044,   148,
     611,   612,  1044,   146,   619,   620,  1044,   140,  1042,   138,
    1042,     6,   150,   151,   639,   640,   106,   107,   647,   648,
     649,   650,   106,   533,   535,   536,    10,    11,   510,   509,
    1061,  1082,  1113,   108,     3,     3,   191,   911,   912,    34,
     804,   805,  1130,  1150,    10,    11,   668,   669,   670,  1150,
    1150,  1150,   120,     8,    10,   124,   568,     8,    10,   126,
    1043,   128,   134,   136,     8,   142,   596,  1046,  1047,   144,
     604,   148,   612,   146,   620,   140,   138,     8,    10,   150,
     640,   106,   649,   651,   652,    10,    11,   538,   537,  1061,
    1082,  1113,   108,  1150,     8,   199,  1020,  1021,    35,   913,
     914,  1129,  1150,    10,    11,   806,   807,   808,     6,   155,
     671,   672,   673,     4,     4,    10,    11,  1052,    21,    22,
      23,  1048,  1049,  1050,  1051,     4,    10,    11,   654,   653,
    1061,  1082,  1113,   108,    28,  1022,  1136,  1150,    10,    11,
     915,   916,   917,     6,   185,   809,   810,   811,  1150,   154,
     159,   686,   687,    37,   674,  1137,    94,   130,   132,     3,
       3,     3,   152,   108,  1150,    10,    11,  1023,  1024,  1025,
       6,   193,   918,   919,   920,  1150,   184,   189,   824,   825,
      38,   812,  1127,   161,   700,   701,   688,  1137,  1150,    10,
      11,   675,   676,   677,     8,     8,     8,     6,  1026,  1150,
     192,   197,   933,   934,    39,   921,  1121,   161,   838,   839,
     826,  1127,  1150,    10,    11,   813,   814,   815,   177,   755,
     756,    10,    11,   702,   703,   704,    10,    11,   689,   690,
     691,     6,   156,   157,   678,   679,   680,   681,  1150,   200,
     201,  1027,  1028,   161,   947,   948,   935,  1121,  1150,    10,
      11,   922,   923,   924,   893,    10,    11,   840,   841,   842,
      10,    11,   827,   828,   829,     6,   186,   187,   816,   817,
     818,   819,   179,   769,   770,   757,  1137,   163,   705,   706,
     707,   157,   160,   692,   693,   694,   695,  1150,   156,   680,
     682,   683,    24,    25,    36,    55,    57,    69,    70,  1029,
    1030,  1031,  1053,  1054,  1055,  1056,  1061,  1082,  1090,  1091,
    1092,  1093,  1097,  1098,  1099,  1100,  1113,  1125,  1002,    10,
      11,   949,   950,   951,    10,    11,   936,   937,   938,     6,
     194,   195,   925,   926,   927,   928,   107,   894,   895,   163,
     843,   844,   845,   187,   190,   830,   831,   832,   833,  1150,
     186,   818,   820,   821,   784,    29,   771,    10,    11,   758,
     759,   760,   162,   167,   713,   714,    40,   708,  1123,   160,
     694,   696,   697,    10,    11,   685,    42,   684,  1071,  1072,
    1073,  1082,  1113,     3,     3,  1150,     3,    10,    11,  1032,
    1033,  1034,  1031,   107,  1003,  1004,   163,   952,   953,   954,
     195,   198,   939,   940,   941,   942,  1150,   194,   927,   929,
     930,   896,   897,   162,   167,   851,   852,   846,  1123,   190,
     832,   834,   835,    10,    11,   823,   822,  1071,  1082,  1113,
     107,   785,   786,     8,    10,    11,   772,   773,   774,   157,
     178,   761,   762,   763,   764,   165,   720,   721,   715,  1123,
    1150,    10,    11,   709,   710,   711,    10,    11,   699,   698,
    1071,  1082,  1113,   158,  1150,  1150,     8,     6,  1150,   202,
     205,   206,   208,  1035,  1036,  1037,  1038,  1039,  1040,  1005,
    1006,   162,   167,   960,   961,   955,  1123,   198,   941,   943,
     944,    10,    11,   932,   931,  1071,  1082,  1113,    10,    11,
     899,   900,   901,    17,    49,    50,    51,    52,   898,  1053,
    1061,  1065,  1066,  1067,  1068,  1082,  1086,  1087,  1088,  1089,
    1090,  1097,  1113,  1124,  1127,   165,   858,   859,   853,  1123,
      10,    11,   847,   848,   849,    10,    11,   837,    61,    62,
      63,    64,   836,  1071,  1074,  1075,  1076,  1077,  1082,  1101,
    1102,  1103,  1104,   188,   787,   788,     6,   180,   181,   775,
     776,   777,   178,   763,   765,   766,   169,   727,   728,   722,
    1123,    10,    11,   716,   717,   718,     6,   209,   712,  1181,
    1182,  1189,   158,     6,  1150,     5,  1041,   202,  1037,    10,
      11,  1008,  1009,  1010,    47,    48,  1007,  1053,  1057,  1058,
    1059,  1060,  1061,  1065,  1082,  1090,  1097,  1113,  1121,  1124,
     165,   967,   968,   962,  1123,    10,    11,   956,   957,   958,
      10,    11,   946,    65,    66,    67,    68,   945,  1071,  1078,
    1079,  1080,  1081,  1082,  1105,  1106,  1107,  1108,   196,   108,
     187,   203,   902,   903,   904,   905,  1139,  1140,  1141,  1150,
       3,     3,   169,   865,   866,   860,  1123,    10,    11,   854,
     855,   856,   850,  1181,   188,     3,     3,    10,    11,   790,
     791,   792,    53,    54,   789,  1053,  1061,  1065,  1082,  1090,
    1097,  1113,  1117,  1118,  1119,  1120,  1124,  1137,     8,   180,
     776,   778,   779,    10,    11,   768,   767,  1071,  1082,  1113,
     173,   734,   735,   729,  1123,    10,    11,   723,   724,   725,
     719,  1181,  1150,   213,  1190,   164,   214,  1183,  1184,  1150,
     207,   108,   195,  1011,  1012,  1013,  1014,  1139,     3,   169,
     974,   975,   969,  1123,    10,    11,   963,   964,   965,   959,
    1181,   196,  1150,  1150,   108,   904,   906,   907,  1140,  1142,
    1143,     6,     8,     8,   173,   872,   873,   867,  1123,    10,
      11,   861,   862,   863,   857,  1181,   164,  1150,  1150,   108,
     157,   793,   794,   795,   796,  1139,     3,    10,    11,   781,
     782,   783,    26,    43,   780,  1069,  1070,  1094,  1095,  1096,
    1137,   158,   171,   741,   742,   736,  1123,    10,    11,   730,
     731,   732,   726,  1181,   168,  1150,    10,    11,  1191,  1192,
    1193,  1185,  1186,   108,  1013,  1015,  1016,     8,   173,   981,
     982,   976,  1123,    10,    11,   970,   971,   972,   966,  1181,
     164,  1149,  1149,    10,    11,   909,   910,   908,  1071,  1074,
    1082,  1101,  1113,    10,    11,  1145,  1146,  1147,  1061,  1113,
    1123,  1144,  1150,   171,   879,   880,   874,  1123,    10,    11,
     868,   869,   870,   864,  1181,   168,   108,   795,   797,   798,
       8,   182,   762,     8,  1150,   175,   748,   749,   743,  1123,
      10,    11,   737,   738,   739,   733,  1181,   166,     6,     4,
     210,    10,  1188,   211,   212,  1187,  1194,  1195,    10,    11,
    1018,  1019,  1017,  1071,  1074,  1082,  1101,  1113,   171,   988,
     989,   983,  1123,    10,    11,   977,   978,   979,   973,  1181,
     168,  1150,  1150,   188,  1148,  1181,   175,   886,   887,   881,
    1123,    10,    11,   875,   876,   877,   871,  1181,   166,    10,
      11,   800,   801,   799,  1071,  1074,  1082,  1101,  1113,   182,
    1149,     6,   750,  1123,    10,    11,   744,   745,   746,   740,
    1181,   170,  1150,   210,     6,  1150,  1150,   196,   175,   995,
     996,   990,  1123,    10,    11,   984,   985,   986,   980,  1181,
     166,   204,   888,  1123,    10,    11,   882,   883,   884,   878,
    1181,   170,   158,     8,  1150,    10,    11,   751,   752,   753,
     747,  1181,   174,   215,     6,     6,   997,  1123,    10,    11,
     991,   992,   993,   987,  1181,   170,    10,    11,   889,   890,
     891,   885,  1181,   174,   754,  1181,   172,  1150,  1150,    10,
      11,   998,   999,  1000,   994,  1181,   174,   892,  1181,   172,
     176,  1001,  1181,   172,   176,   176
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (&yylloc, osoption, parserData, osglData, osnlData, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, scanner)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, osoption, parserData, osglData, osnlData); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData, osglData, osnlData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (osoption);
  YYUSE (parserData);
  YYUSE (osglData);
  YYUSE (osnlData);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData, osglData, osnlData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData, osglData, osnlData);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, osoption, parserData, osglData, osnlData)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osoption, parserData, osglData, osnlData);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, osoption, parserData, osglData, osnlData); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, osoption, parserData, osglData, osnlData)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (osoption);
  YYUSE (parserData);
  YYUSE (osglData);
  YYUSE (osnlData);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (OSOption *osoption, OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData)
#else
int
yyparse (osoption, parserData, osglData, osnlData)
    OSOption *osoption;
    OSoLParserData *parserData;
    OSgLParserData *osglData;
    OSnLParserData *osnlData;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

    {
#ifdef DEBUG
    yydebug = 1;
#endif
}
    break;

  case 5:

    {
#ifdef DEBUG
    yydebug = 1;
#endif
    parserData->parser_errors = "";
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;
}
    break;

  case 12:

    {
        if (parserData->parser_errors != "")
        {
            parserData->parser_errors += ("\n\nOSoL input is either not valid or well formed.\n"); 
            osolerror( NULL, osoption, parserData, osglData, osnlData, parserData->parser_errors);
        }
    }
    break;

  case 14:

    { parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "unexpected end of file, expecting </osol>");}
    break;

  case 17:

    {
    if (!osoption->setHeader(osglData->fileName, osglData->source,
            osglData->description, osglData->fileCreator, osglData->licence) )     
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setHeader failed");
}
    break;

  case 20:

    {
    parserData->serviceURIPresent          = false;    
    parserData->serviceNamePresent         = false;
    parserData->instanceNamePresent        = false;
    parserData->instanceLocationPresent    = false;
    parserData->jobIDPresent               = false;
    parserData->solverToInvokePresent      = false;
    parserData->licensePresent             = false;
    parserData->usernamePresent            = false;
    parserData->passwordPresent            = false;
    parserData->contactPresent             = false;
    parserData->otherGeneralOptionsPresent = false;
    osoption->general = new GeneralOption();
}
    break;

  case 41:

    {
    if (parserData->serviceURIPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <serviceURI>");
    else
        parserData->serviceURIPresent = true;
    
}
    break;

  case 47:

    {
        if (osoption->setServiceURI((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setServiceURI failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 49:

    {
        if (parserData->serviceNamePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <serviceName>");
        parserData->serviceNamePresent = true;
    }
    break;

  case 55:

    {
        if (osoption->setServiceName((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setServiceName failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 57:

    {    if (parserData->instanceNamePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <instanceName>");
        parserData->instanceNamePresent = true;
    }
    break;

  case 63:

    {
        if (osoption->setInstanceName((yyvsp[(1) - (1)].sval)) == false) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setInstanceName failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 64:

    {
    if (osoption->setInstanceLocation(parserData->tempStr,parserData->typeAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setInstanceLocation failed");
    parserData->errorText = NULL;
}
    break;

  case 65:

    {
        if (parserData->instanceLocationPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <instanceLocation>");
        parserData->instanceLocationPresent = true;
        parserData->typeAttribute = "local";
    }
    break;

  case 67:

    {   
        if (verifyLocationType(parserData->typeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "instance location type not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 68:

    { 
    parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 74:

    {    
        parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval)); 
    }
    break;

  case 76:

    {    if (parserData->jobIDPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <jobID>");
        parserData->jobIDPresent = true;
    }
    break;

  case 82:

    {
        if (osoption->setJobID((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setJobID failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 84:

    {
        if (parserData->solverToInvokePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <solverToInvoke>");
        parserData->solverToInvokePresent = true;
    }
    break;

  case 90:

    {
        if (osoption->setSolverToInvoke((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setSolverToInvoke failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 92:

    {
    if (parserData->licensePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <license>");
    parserData->licensePresent = true;    
}
    break;

  case 98:

    {
        if (osoption->setLicense((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setLicense failed");
        free((yyvsp[(1) - (1)].sval));
        parserData->errorText = NULL;
    }
    break;

  case 100:

    {    if (parserData->usernamePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <username>");
    parserData->usernamePresent = true;    
}
    break;

  case 106:

    {
        if (osoption->setUserName((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setUsername failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 108:

    {    if (parserData->passwordPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <password>");
    parserData->passwordPresent = true;    
}
    break;

  case 114:

    {
        if (osoption->setPassword((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setPassword failed");
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
    }
    break;

  case 115:

    {
    if (osoption->setContact(parserData->tempStr,parserData->typeAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setContact failed");
    parserData->errorText = NULL;
}
    break;

  case 116:

    {
    if (parserData->contactPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <contact>");
    parserData->contactPresent = true;
    parserData->typeAttribute = "osp";
    parserData->tempStr = "";
}
    break;

  case 118:

    {   
        if (verifyTransportType(parserData->typeAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "transport type not recognized");
    }
    break;

  case 119:

    { 
        parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
        free((yyvsp[(2) - (3)].sval));
    }
    break;

  case 125:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval);
        free((yyvsp[(1) - (1)].sval));
    }
    break;

  case 126:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 127:

    {
        if (parserData->otherGeneralOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <general> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
        parserData->otherGeneralOptionsPresent = true;
    }
    break;

  case 128:

    {
        if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other general options cannot be negative");
        parserData->numberOf = parserData->tempInt;
        parserData->kounter = 0;
    }
    break;

  case 129:

    {
        if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
    break;

  case 130:

    {
        if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    }
    break;

  case 137:

    {    
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherGeneralOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherGeneralOption failed");
    }
    break;

  case 138:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 139:

    {
    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 142:

    {    if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
    break;

  case 149:

    {
    parserData->minDiskSpacePresent = false;    
    parserData->minMemoryPresent = false;
    parserData->minCPUSpeedPresent = false;
    parserData->minCPUNumberPresent = false;
    parserData->otherSystemOptionsPresent = false;
    osoption->system = new SystemOption();
}
    break;

  case 164:

    {    if (parserData->minDiskSpacePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minDiskSpace element allowed");
        parserData->minDiskSpacePresent = true;    
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "byte";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 171:

    {
    if (osoption->setMinDiskSpace(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinDiskSpace failed");
    parserData->errorText = NULL;
}
    break;

  case 173:

    {    if (parserData->minMemoryPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minMemory element allowed");
        parserData->minMemoryPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "byte";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 180:

    {
    if (osoption->setMinMemorySize(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinMemorySize failed");
    parserData->errorText = NULL;
}
    break;

  case 182:

    {    if (parserData->minCPUSpeedPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minCPUSpeed element allowed");
        parserData->minCPUSpeedPresent = true;
        parserData->unitAttributePresent = false;    
        parserData->descriptionAttributePresent = false;    
        parserData->unitAttribute = "hertz";    
        parserData->descriptionAttribute = "";
    }
    break;

  case 189:

    {    
    if (osoption->setMinCPUSpeed(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinCPUSpeed failed");
    parserData->errorText = NULL;
}
    break;

  case 191:

    {    if (parserData->minCPUNumberPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one minCPUNumber element allowed");
        parserData->minCPUNumberPresent = true;
        parserData->descriptionAttributePresent = false;    
        parserData->descriptionAttribute = "";    
    }
    break;

  case 195:

    {
    if (osoption->setMinCPUNumber((yyvsp[(1) - (1)].ival), parserData->descriptionAttribute) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setMinCPUNumber failed");
    //free($1); 
    parserData->errorText = NULL; 
}
    break;

  case 196:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 197:

    {
    if (parserData->otherSystemOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <system> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->otherSystemOptionsPresent = true;
}
    break;

  case 198:

    {
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other system options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 199:

    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
    break;

  case 200:

    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    }
    break;

  case 207:

    {
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherSystemOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherSystemOption failed");
    }
    break;

  case 208:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 209:

    {    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 212:

    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
    break;

  case 219:

    {
    parserData->serviceTypePresent = false;    
    parserData->otherServiceOptionsPresent = false;
    osoption->service = new ServiceOption();
}
    break;

  case 231:

    {    if (parserData->serviceTypePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one currentState element allowed");
        parserData->serviceTypePresent = true;
    }
    break;

  case 237:

    {
        parserData->tempStr = (yyvsp[(1) - (1)].sval); 
        free((yyvsp[(1) - (1)].sval));
        if (osoption->setServiceType(parserData->tempStr) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setServiceType failed; current system state not recognized");
        parserData->errorText = NULL;
    }
    break;

  case 238:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 239:

    {
    if (parserData->otherServiceOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <service> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
    parserData->otherServiceOptionsPresent = true;
}
    break;

  case 240:

    {
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other service options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 241:

    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
    break;

  case 242:

    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    }
    break;

  case 249:

    {    
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherServiceOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherServiceOption failed");
    }
    break;

  case 250:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 251:

    {    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 254:

    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
    break;

  case 261:

    {
    parserData->maxTimePresent = false;    
    parserData->requestedStartTimePresent = false;    
    parserData->dependenciesPresent = false;    
    parserData->requiredDirectoriesPresent = false;    
    parserData->requiredFilesPresent = false;    
    parserData->directoriesToMakePresent = false;    
    parserData->filesToMakePresent = false;    
    parserData->inputDirectoriesToMovePresent = false;    
    parserData->inputFilesToMovePresent = false;    
    parserData->outputDirectoriesToMovePresent = false;    
    parserData->outputFilesToMovePresent = false;    
    parserData->filesToDeletePresent = false;    
    parserData->directoriesToDeletePresent = false;    
    parserData->processesToKillPresent = false;    
    parserData->otherJobOptionsPresent = false;     
    osoption->job = new JobOption();
 }
    break;

  case 285:

    {    
    if (osoption->setMaxTime(parserData->maxTimeValue, parserData->unitAttribute) == false)       
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "max time request could not be honored");
}
    break;

  case 286:

    {    
    if (parserData->maxTimePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <maxTime> element allowed");
    parserData->maxTimePresent = true;
    parserData->unitAttributePresent = false;    
    parserData->unitAttribute = "second"; 
    parserData->maxTimeValue = OSDBL_MAX;
}
    break;

  case 295:

    {
    parserData->maxTimeValue = parserData->tempVal;
}
    break;

  case 297:

    {    if (parserData->requestedStartTimePresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one requestedStartTime element allowed");
        parserData->requestedStartTimePresent = true;
    }
    break;

  case 303:

    {
        if (osoption->setRequestedStartTime((yyvsp[(1) - (1)].sval)) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setRequestedStartTime failed");    
        free((yyvsp[(1) - (1)].sval)); 
        parserData->errorText = NULL;
        }
    break;

  case 304:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setJobDependencies(parserData->numberOf, parserData->jobDependencies) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <job> <dependencies> failed");
    delete[] parserData->jobDependencies;
    parserData->jobDependencies = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 305:

    {
    if (parserData->dependenciesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <dependencies> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->dependenciesPresent = true;
}
    break;

  case 311:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few job IDs in <dependencies> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 314:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many job IDs in <dependencies> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->jobDependencies[parserData->kounter] = (yyvsp[(3) - (4)].sval);
        parserData->kounter++;
    }
    free((yyvsp[(3) - (4)].sval)); 
}
    break;

  case 315:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setRequiredDirectories(parserData->numberOf,parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <requiredDirectories> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 316:

    {
    if (parserData->requiredDirectoriesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <requiredDirectories> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->requiredDirectoriesPresent = true;
}
    break;

  case 321:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <requiredDirectories> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 322:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setRequiredFiles(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <requiredFiles> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 323:

    {
    if (parserData->requiredFilesPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <requiredFiles> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->requiredFilesPresent = true;
}
    break;

  case 328:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <requiredFiles> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 329:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setDirectoriesToMake(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <directoriesToMake> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 330:

    {
    if (parserData->directoriesToMakePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <directoriesToMake> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->directoriesToMakePresent = true;
}
    break;

  case 335:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <directoriesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 336:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setFilesToMake(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <filesToMake> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 337:

    {
    if (parserData->filesToMakePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <filesToMake> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->filesToMakePresent = true;
}
    break;

  case 342:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <filesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 343:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_input_dir, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputDirectoriesToMove> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;
}
    break;

  case 344:

    {
    if (parserData->inputDirectoriesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <inputDirectoriesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->inputDirectoriesToMovePresent = true;
}
    break;

  case 350:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <inputDirectoriesToMove> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 354:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_input_file, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputFilesToMove> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 355:

    {
    if (parserData->inputFilesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <inputFilesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->inputFilesToMovePresent = true;
}
    break;

  case 361:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <inputFilesToMove> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 365:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_output_file, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputDirectoriesToMake> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 366:

    {
    if (parserData->outputFilesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <outputFilesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->outputFilesToMovePresent = true;
}
    break;

  case 372:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <outputFilesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 376:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setPathPairs(ENUM_PATHPAIR_output_dir, parserData->fromPaths, 
                parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <inputDirectoriesToMake> failed");
    delete[] parserData->fromPaths;
    delete[] parserData->toPaths;
    delete[] parserData->makeCopy;
    parserData->fromPaths = NULL;
    parserData->toPaths   = NULL;
    parserData->makeCopy  = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 377:

    {
    if (parserData->outputDirectoriesToMovePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <outputDirectoriesToMove> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->outputDirectoriesToMovePresent = true;
}
    break;

  case 383:

    {
    if (parserData->kounter < parserData->numberOfPathPairs)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few path pairs in <outputDirectoriesToMake> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 387:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setFilesToDelete(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <filesToDelete> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 388:

    {
    if (parserData->filesToDeletePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <filesToDelete> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->filesToDeletePresent = true;
}
    break;

  case 394:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <filesToDelete> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 395:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setDirectoriesToDelete(parserData->numberOf, parserData->paths) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <directoriesToDelete> failed");
    delete[] parserData->paths;
    parserData->paths = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 396:

    {
    if (parserData->directoriesToDeletePresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <directoriesToDelete> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->directoriesToDeletePresent = true;
}
    break;

  case 402:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few paths in <directoriesToDelete> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 403:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setProcessesToKill(parserData->numberOf, parserData->processesToKill) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <processesToKill> failed");
    delete[] parserData->processesToKill;
    parserData->processesToKill = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 404:

    {
    if (parserData->processesToKillPresent)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one <processesToKill> element allowed");
        parserData->ignoreDataAfterErrors = true;
    }
    parserData->processesToKillPresent = true;
}
    break;

  case 410:

    {
    if (parserData->kounter < parserData->numberOf)
    {
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few process IDs in <processesToKill> element");
        parserData->ignoreDataAfterErrors = true;        
    }
}
    break;

  case 413:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
    if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many process IDs in <processesToKill> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->processesToKill[parserData->kounter] = (yyvsp[(3) - (4)].sval);
        parserData->kounter++;
    }
    free((yyvsp[(3) - (4)].sval)); 
}
    break;

  case 414:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 415:

    {
    if (parserData->otherJobOptionsPresent)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated element: <job> <otherOptions>");
            parserData->ignoreDataAfterErrors = true;            
        }
    parserData->otherJobOptionsPresent = true;
}
    break;

  case 416:

    {
    if (parserData->tempInt < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other job options cannot be negative");
    parserData->numberOf = parserData->tempInt;
    parserData->kounter = 0;
}
    break;

  case 417:

    {    if (parserData->numberOf > 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <other> element");
    }
    break;

  case 418:

    {    if (parserData->kounter < parserData->numberOf - 1)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <other> elements than specified");
    }
    break;

  case 425:

    {
        parserData->kounter++;
        if (!parserData->ignoreDataAfterErrors)
            if (osoption->setAnOtherJobOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setOtherJobOption failed");
    }
    break;

  case 426:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <other> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 427:

    {
    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> must have name attribute");
}
    break;

  case 430:

    {
        if (parserData->nameAttribute.length() == 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "otherOption name cannot be empty");
    }
    break;

  case 437:

    {
    osoption->optimization = new OptimizationOption();
    parserData->numberOfVariablesPresent = false;
    parserData->numberOfObjectivesPresent = false;
    parserData->numberOfConstraintsPresent = false;
}
    break;

  case 441:

    {    
        parserData->numberOfVariables = parserData->tempInt; 
        if (osoption->setNumberOfVariables(parserData->tempInt) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfVariables failed");
    }
    break;

  case 442:

    {
        parserData->numberOfConstraints = parserData->tempInt; 
        if (osoption->setNumberOfConstraints(parserData->tempInt) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfConstraints failed");
    }
    break;

  case 443:

    {    
        parserData->numberOfObjectives = parserData->tempInt; 
        if (osoption->setNumberOfObjectives(parserData->tempInt) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfObjectives failed");
    }
    break;

  case 451:

    {
    parserData->numberOfOtherVariableOptions = 0;
    osoption->optimization->variables = new VariableOption();
}
    break;

  case 452:

    {    
    if (osoption->setNumberOfOtherVariableOptions(parserData->numberOfOtherVariableOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherVariableOptions failed");
    parserData->iOther = 0;
}
    break;

  case 454:

    {    
    parserData->numberOfOtherVariableOptions = parserData->tempInt;
}
    break;

  case 459:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

}
    break;

  case 461:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitVarValues(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialVariableValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 462:

    {
    parserData->numberOfVarAttributePresent = false;
}
    break;

  case 463:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfVar];
    parserData->namArray = new std::string[parserData->numberOfVar];
    parserData->valArray = new      double[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 464:

    {
        if (parserData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValues>: expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 465:

    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValues>: fewer <var> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 472:

    {
    parserData->kounter++;
}
    break;

  case 473:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
}
    break;

  case 474:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
}
    break;

  case 477:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 478:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 479:

    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        if (!parserData->ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 483:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitVarValuesString(parserData->numberOfVar, parserData->idxArray, parserData->valueString, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialVariableValuesString> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valueString;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valueString = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 484:

    {
    parserData->numberOfVarAttributePresent = false;
}
    break;

  case 485:

    {
    parserData->kounter = 0;
    parserData->idxArray    = new         int[parserData->numberOfVar];
    parserData->namArray    = new std::string[parserData->numberOfVar];
    parserData->valueString = new std::string[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valueString[i] = "";
}
    break;

  case 486:

    {
        if (parserData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialVariableValuesString>: expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 487:

    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too few initial values in <initialVariableValuesString> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 494:

    {
    parserData->kounter++;
}
    break;

  case 495:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->valueAttribute = "48r 87e WY EUV e7 df"; //random string...
}
    break;

  case 496:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
}
    break;

  case 499:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 500:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 501:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->valueString[parserData->kounter] = parserData->valueAttribute;
    }
    break;

  case 506:

    {
    osoption->optimization->variables->initialBasisStatus = new BasisStatus();
}
    break;

  case 513:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 514:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 515:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 522:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 523:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 524:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 531:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 532:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 533:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 540:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 541:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 542:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 549:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 550:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 551:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 558:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 559:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 560:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 567:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 568:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 569:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 576:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setIntegerVariableBranchingWeights(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialVariableValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 577:

    {
    parserData->numberOfVarAttributePresent = false;
}
    break;

  case 578:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfVar];
    parserData->namArray = new std::string[parserData->numberOfVar];
    parserData->valArray = new      double[parserData->numberOfVar];
    for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 579:

    {
        if (parserData->numberOfVar > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <var> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 580:

    {
        if (parserData->kounter < parserData->numberOfVar)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <var> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 587:

    {
    parserData->kounter++;
}
    break;

  case 588:

    {    
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;
    parserData->valueAttribute = "1.0";
}
    break;

  case 589:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<var> element must have idx attribute");
}
    break;

  case 592:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
        if (!parserData->ignoreDataAfterErrors)
            parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 593:

    {
        if (!parserData->ignoreDataAfterErrors)
            parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 594:

    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        if (!parserData->ignoreDataAfterErrors)
            parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 598:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 599:

    {
    parserData->sosIdxAttributePresent = false;    
    parserData->currentSOS = 0;
}
    break;

  case 600:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <sos> elements must be nonnegative");
    parserData->numberOfSOS = (yyvsp[(3) - (4)].ival);
}
    break;

  case 601:

    {
        if (parserData->numberOfSOS > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <sos> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 602:

    {    if (parserData->currentSOS != parserData->numberOfSOS)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <sos> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 608:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setAnotherSOSVariableBranchingWeight(parserData->sosIdx, 
                    parserData->numberOfVar, parserData->groupWeight,
                    parserData->idxArray,     parserData->valArray, parserData->namArray) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "error processing SOS branching weights");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->currentSOS++;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 609:

    {
    if (parserData->currentSOS >= parserData->numberOfSOS)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many SOS branching weights");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->sosIdxAttributePresent = false;
    parserData->groupWeightAttributePresent = false;
    parserData->numberOfVarAttributePresent = false;
    parserData->groupWeight = 1.0;
    parserData->numberOfSOSVar = 0;
}
    break;

  case 610:

    {
    if (!parserData->sosIdxAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "SOS index required");
    if (!parserData->numberOfVarAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVar required");
}
    break;

  case 614:

    {
        parserData->kounter = 0;
        parserData->idxArray = new         int[parserData->numberOfVar];
        parserData->namArray = new std::string[parserData->numberOfVar];
        parserData->valArray = new      double[parserData->numberOfVar];
        for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
        parserData->numberOfVarAttributePresent = true;
    }
    break;

  case 623:

    {      
        parserData->iOther++;
    }
    break;

  case 624:

    {
    if (parserData->iOther >= parserData->numberOfOtherVariableOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <otherVariableOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->numberOfVarAttributePresent = false;
    parserData->numberOfVar = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->varTypeAttributePresent = false;    
    parserData->varTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_variables;
}
    break;

  case 625:

    {
        if (!parserData->nameAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherVariableOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfVar,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->varTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    }
    break;

  case 628:

    {
        parserData->kounter = 0;
    }
    break;

  case 629:

    {
        parserData->kounter = 0;
    }
    break;

  case 647:

    {     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherVariableOptionVar(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other variable option <var> element failed");
    parserData->kounter++;
}
    break;

  case 648:

    {
    if (parserData->kounter >= parserData->numberOfVar)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}
    break;

  case 652:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index must be nonnegative");
        if (osoption->optimization->numberOfVariables >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "variable index exceeds upper limit");
        };
    }
    break;

  case 662:

    {
    parserData->numberOfOtherObjectiveOptions = 0; 
    osoption->optimization->objectives = new ObjectiveOption();
}
    break;

  case 663:

    {    
    if (osoption->setNumberOfOtherObjectiveOptions(parserData->numberOfOtherObjectiveOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherVariableOptions failed");
    parserData->iOther = 0;
}
    break;

  case 665:

    {    
    parserData->numberOfOtherObjectiveOptions = parserData->tempInt;
}
    break;

  case 670:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

}
    break;

  case 672:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitObjValues(parserData->numberOfObj, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialObjectiveValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 673:

    {
    parserData->numberOfObjAttributePresent = false;
}
    break;

  case 674:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfObj];
    parserData->namArray = new std::string[parserData->numberOfObj];
    parserData->valArray = new      double[parserData->numberOfObj];
    for (int i=0; i < parserData->numberOfObj; i++) parserData->idxArray[i] = -1;
    for (int i=0; i < parserData->numberOfObj; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfObj; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 675:

    {    
        if (parserData->numberOfObj > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveValues>: expected at least one <obj> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 676:

    {
        if (parserData->kounter < parserData->numberOfObj)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveValues>: fewer <obj> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 683:

    {
    parserData->kounter++;
}
    break;

  case 684:

    {    
    if (parserData->kounter >= parserData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <obj> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->idxAttribute = -1;
}
    break;

  case 688:

    {
        if (parserData->idxAttribute >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 689:

    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 690:

    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 694:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitObjBounds(parserData->numberOfObj, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialObjectiveBounds> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->lbValArray;
    delete[] parserData->ubValArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->lbValArray = NULL;
    parserData->ubValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 695:

    {
    parserData->numberOfObjAttributePresent = false;
}
    break;

  case 696:

    {
    parserData->kounter = 0;
    parserData->idxArray   = new         int[parserData->numberOfObj];
    parserData->lbValArray = new      double[parserData->numberOfObj];
    parserData->ubValArray = new      double[parserData->numberOfObj];
    parserData->namArray   = new std::string[parserData->numberOfObj];
    for (int i=0; i < parserData->numberOfObj; i++) parserData->idxArray[i] = -1;
    for (int i=0; i < parserData->numberOfObj; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfObj; i++) parserData->lbValArray[i] = OSNaN();
    for (int i=0; i < parserData->numberOfObj; i++) parserData->ubValArray[i] = OSNaN();
}
    break;

  case 697:

    {
        if (parserData->numberOfObj > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveBounds>: expected at least one <obj> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 698:

    {
        if (parserData->kounter < parserData->numberOfObj)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialObjectiveBounds>: fewer <obj> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 705:

    {
    parserData->kounter++;
}
    break;

  case 706:

    {    
    if (parserData->kounter >= parserData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <var> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->lbValueAttributePresent = false;
    parserData->ubValueAttributePresent = false;
    parserData->idxAttribute = -1;
    parserData->lbValueAttribute = "-INF";
    parserData->ubValueAttribute = "INF";
}
    break;

  case 710:

    {
        if (parserData->idxAttribute >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be nonnegative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfVariables)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 711:

    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 712:

    {
        if (parserData->lbValueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
    }
    break;

  case 713:

    {
        if (parserData->ubValueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->ubValArray[parserData->kounter] = os_strtod((parserData->ubValueAttribute).c_str(), NULL);
    }
    break;

  case 718:

    {
    osoption->optimization->objectives->initialBasisStatus = new BasisStatus();
}
    break;

  case 725:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 726:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 727:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 734:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 735:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 736:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 743:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 744:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 745:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 752:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 753:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 754:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 761:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 762:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 763:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 770:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 771:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 772:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 779:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set objectives unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 780:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 781:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 789:

    {      
        parserData->iOther++;  
    }
    break;

  case 790:

    {
    if (parserData->iOther >= parserData->numberOfOtherObjectiveOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <otherObjectiveOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->numberOfObjAttributePresent = false;    
    parserData->numberOfObj = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->objTypeAttributePresent = false;    
    parserData->objTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_objectives;
}
    break;

  case 791:

    {
        if (!parserData->nameAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherObjectiveOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfObj,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->objTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    }
    break;

  case 794:

    {
        parserData->kounter = 0;
    }
    break;

  case 795:

    {
        parserData->kounter = 0;
    }
    break;

  case 813:

    {  
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherObjectiveOptionObj(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other objective option <obj> element failed");
    parserData->kounter++;
}
    break;

  case 814:

    {

    if (parserData->kounter >= parserData->numberOfObj)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <obj> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->idxAttribute = -1;
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}
    break;

  case 818:

    {
        if (parserData->idxAttribute >= 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index must be negative");
        if (osoption->optimization->numberOfObjectives >= 0)
        {
            if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "objective index exceeds limit");
        };
    }
    break;

  case 828:

    {
    parserData->numberOfOtherConstraintOptions = 0; 
    osoption->optimization->constraints = new ConstraintOption();
}
    break;

  case 829:

    {    
    if (osoption->setNumberOfOtherConstraintOptions(parserData->numberOfOtherConstraintOptions) == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfOtherConstraintOptions failed");
    parserData->iOther = 0;
}
    break;

  case 831:

    {    
    parserData->numberOfOtherConstraintOptions = parserData->tempInt;
}
    break;

  case 836:

    {
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        

}
    break;

  case 838:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitConValues(parserData->numberOfCon, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialConstraintValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->valArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->valArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 839:

    {
    parserData->numberOfConAttributePresent = false;
}
    break;

  case 840:

    {
    parserData->kounter = 0;
    parserData->idxArray = new         int[parserData->numberOfCon];
    parserData->namArray = new std::string[parserData->numberOfCon];
    parserData->valArray = new      double[parserData->numberOfCon];
    for (int i=0; i < parserData->numberOfCon; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfCon; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 841:

    {
        if (parserData->numberOfCon > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialConstraintValues>: expected at least one <con element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 842:

    {
        if (parserData->kounter < parserData->numberOfCon)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialConstraintValues>: fewer <con> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 849:

    {
    parserData->kounter++;
}
    break;

  case 850:

    {    
    if (parserData->kounter >= parserData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
}
    break;

  case 851:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<con> element must have idx attribute");
}
    break;

  case 854:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index exceeds upper limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 855:

    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 856:

    {
        if (parserData->valueAttribute == "")
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected an integer or floating point value");
        parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
    }
    break;

  case 860:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitDualValues(parserData->numberOfCon, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <initialConstraintValues> failed");
    delete[] parserData->idxArray;
    delete[] parserData->namArray;
    delete[] parserData->lbValArray;
    delete[] parserData->ubValArray;
    parserData->idxArray = NULL;
    parserData->namArray = NULL;
    parserData->lbValArray = NULL;
    parserData->ubValArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 861:

    {
    parserData->numberOfConAttributePresent = false;
}
    break;

  case 862:

    {
    parserData->kounter = 0;
    parserData->idxArray   = new         int[parserData->numberOfCon];
    parserData->namArray   = new std::string[parserData->numberOfCon];
    parserData->lbValArray = new      double[parserData->numberOfCon];
    parserData->ubValArray = new      double[parserData->numberOfCon];
    for (int i=0; i < parserData->numberOfCon; i++) parserData->namArray[i] = "";
    for (int i=0; i < parserData->numberOfCon; i++) parserData->lbValArray[i] = OSNaN();
    for (int i=0; i < parserData->numberOfCon; i++) parserData->ubValArray[i] = OSNaN();
}
    break;

  case 863:

    {
        if (parserData->numberOfCon > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialDualValues>: expected at least one <con> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 864:

    {
        if (parserData->kounter < parserData->numberOfCon)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<initialDualValues>: fewer <con> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 871:

    {    
    parserData->kounter++;
}
    break;

  case 872:

    {    
    if (parserData->kounter >= parserData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;
    parserData->nameAttributePresent = false;
    parserData->nameAttribute = "";
    parserData->lbValueAttributePresent = false;
    parserData->ubValueAttributePresent = false;
    parserData->lbDualValue = OSNaN();
    parserData->ubDualValue = OSNaN();
}
    break;

  case 873:

    {
    if (parserData->idxAttributePresent == false)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<con> element must have idx attribute");
}
    break;

  case 876:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index exceeds upper limit");
        };
        parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
    }
    break;

  case 877:

    {
        parserData->namArray[parserData->kounter] = parserData->nameAttribute;
    }
    break;

  case 878:

    {
        parserData->lbValArray[parserData->kounter] = parserData->lbDualValue;
    }
    break;

  case 879:

    {
        parserData->ubValArray[parserData->kounter] = parserData->ubDualValue;
    }
    break;

  case 884:

    {
    osoption->optimization->constraints->initialBasisStatus = new BasisStatus();
}
    break;

  case 891:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks basic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 892:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 893:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 900:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atLower failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 901:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 902:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 909:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atUpper failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 910:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 911:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 918:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks atEquality failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 919:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 920:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 927:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks isFree failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 928:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 929:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 936:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set variables superbasic failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 937:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 938:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 945:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set slacks unknown failed");    
    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    parserData->suppressFurtherErrorMessages = false;
    parserData->ignoreDataAfterErrors = false;        
}
    break;

  case 946:

    {
    osglData->osglNumberOfEl = 0;
    osglData->osglNumberOfElPresent= false;
}
    break;

  case 947:

    {
    osglData->osglCounter = 0; 
    osglData->osglNumberOfEl = parserData->numberOf;
    osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 955:

    {      
        parserData->iOther++;  
    }
    break;

  case 956:

    {
    if (parserData->iOther >= parserData->numberOfOtherConstraintOptions)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <otherConstraintOptions> than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->numberOfConAttributePresent = false;    
    parserData->numberOfCon = 0;
    parserData->numberOfEnumerationsAttributePresent = false;    
    parserData->numberOfEnumerations = 0;
    parserData->nameAttributePresent = false;    
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->solverAttributePresent = false;    
    parserData->solverAttribute = "";
    parserData->categoryAttributePresent = false;    
    parserData->categoryAttribute = "";
    parserData->typeAttributePresent = false;    
    parserData->typeAttribute = "";
    parserData->conTypeAttributePresent = false;    
    parserData->conTypeAttribute = "";
    parserData->enumTypeAttributePresent = false;    
    parserData->enumTypeAttribute = "";
    parserData->descriptionAttributePresent = false;    
    parserData->descriptionAttribute = "";    
    parserData->otherOptionType = ENUM_PROBLEM_COMPONENT_constraints;
}
    break;

  case 957:

    {
        if(!parserData->nameAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element requires name attribute"); 
        if (!parserData->ignoreDataAfterErrors)
            if (!osoption->setOtherConstraintOptionAttributes(
                    parserData->iOther,
                    parserData->numberOfCon,
                    parserData->numberOfEnumerations,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->conTypeAttribute,
                    parserData->enumTypeAttribute,
                    parserData->descriptionAttribute) )
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element could not be initialed"); 
    }
    break;

  case 960:

    {
        parserData->kounter = 0;
    }
    break;

  case 961:

    {
        parserData->kounter = 0;
    }
    break;

  case 979:

    {     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherConstraintOptionCon(
                parserData->iOther, 
                parserData->kounter,
                parserData->idxAttribute, 
                parserData->nameAttribute,
                parserData->valueAttribute,
                parserData->lbValueAttribute, 
                parserData->ubValueAttribute) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set other constraint option <con> element failed");
    parserData->kounter++;
}
    break;

  case 980:

    {
    if (parserData->kounter >= parserData->numberOfCon)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <con> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->idxAttributePresent = false;    
    parserData->nameAttributePresent = false;    
    parserData->nameAttribute = "";
    parserData->valueAttributePresent = false;    
    parserData->valueAttribute = "";
    parserData->lbValueAttributePresent = false;    
    parserData->lbValueAttribute = "";
    parserData->ubValueAttributePresent = false;    
    parserData->ubValueAttribute = "";
}
    break;

  case 984:

    {
        if (parserData->idxAttribute < 0)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index must be nonnegative");
        if (osoption->optimization->numberOfConstraints >= 0)
        {
            if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "constraint index exceeds upper limit");
        };
    }
    break;

  case 993:

    {
        parserData->suppressFurtherErrorMessages = false;
        parserData->ignoreDataAfterErrors = false;        
    }
    break;

  case 995:

    {
    if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setNumberOfSolverOptions failed");
    parserData->iOption = 0;
}
    break;

  case 996:

    {
        if (parserData->numberOfSolverOptions > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <solverOption> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 997:

    {
        if (parserData->iOption != parserData->numberOfSolverOptions)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <solverOption> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 1002:

    {
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setSolverOptionContent(
                    parserData->iOption, 
                    parserData->numberOfItems,
                    parserData->nameAttribute,
                    parserData->valueAttribute,
                    parserData->solverAttribute,
                    parserData->categoryAttribute,
                    parserData->typeAttribute,
                    parserData->descriptionAttribute,
                    parserData->itemList) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "setSolverOptionContent failed");
    if (parserData->numberOfItems > 0)
        delete[] parserData->itemList;
    parserData->itemList = NULL;
    parserData->iOption++;
}
    break;

  case 1003:

    {
    parserData->nameAttributePresent = false;
    parserData->valueAttributePresent = false;
    parserData->solverAttributePresent = false;
    parserData->categoryAttributePresent = false;
    parserData->typeAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->numberOfItemsPresent = false;
    parserData->valueAttribute = "";
    parserData->solverAttribute = "";
    parserData->categoryAttribute = "";
    parserData->typeAttribute = "";
    parserData->descriptionAttribute = "";
    parserData->numberOfItems = 0;
    parserData->kounter = 0;
}
    break;

  case 1004:

    {
    if (!parserData->nameAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "name attribute must be present");
}
    break;

  case 1013:

    {
            parserData->itemList = new std::string[parserData->numberOfItems];
    }
    break;

  case 1014:

    {
        if (parserData->numberOfItems > 0)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "expected at least one <item> element");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 1015:

    {
        if (parserData->kounter < parserData->numberOfItems)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer <item> elements than specified");
            parserData->ignoreDataAfterErrors = true;        
        }
    }
    break;

  case 1022:

    {    
    parserData->itemList[parserData->kounter] = parserData->itemContent;
    parserData->kounter++;
}
    break;

  case 1023:

    {
        if (parserData->kounter >= parserData->numberOfItems)
            if (!parserData->suppressFurtherErrorMessages)
            {
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <item> elements than specified");
                parserData->suppressFurtherErrorMessages = true;
                parserData->ignoreDataAfterErrors = true;
            }
        parserData->itemContent = "";            
    }
    break;

  case 1028:

    {
    if (parserData->kounter >= parserData->numberOf)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <item> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    parserData->itemContent = (yyvsp[(1) - (1)].sval); 
    free((yyvsp[(1) - (1)].sval));
}
    break;

  case 1031:

    {
    if (parserData->kounter >= parserData->numberOf)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many paths in <requiredDirectories> element");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
    {
        parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
        parserData->kounter++;
    }
    free((yyvsp[(3) - (4)].sval)); 
}
    break;

  case 1032:

    {    
    if (parserData->kounter >= parserData->numberOfPathPairs)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many path pairs");
    else
    {
        if (!parserData->pathPairFromPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "\"from\" attribute must be present");
        if (!parserData->pathPairToPresent)
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "\"to\" attribute must be present");
           parserData->fromPaths[parserData->kounter] = parserData->pathPairFrom;
           parserData->toPaths[parserData->kounter] = parserData->pathPairTo;
        parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
         parserData->kounter++;
    }
}
    break;

  case 1033:

    {
//    if (parserData->kounter >= parserData->numberOfPathPairs)
//        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "too many path pairs");
    parserData->pathPairFrom = "";
    parserData->pathPairTo = "";
    parserData->pathPairFromPresent = false;
    parserData->pathPairToPresent = false;
    parserData->pathPairMakeCopyPresent = false;
    parserData->pathPairMakeCopy = false;
}
    break;

  case 1034:

    {
//    parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
}
    break;

  case 1040:

    {
    if (parserData->pathPairFromPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"from\" attribute allowed");
    parserData->pathPairFromPresent = true;
    parserData->pathPairFrom = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1041:

    {
    if (parserData->pathPairToPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"to\" attribute allowed");
    parserData->pathPairToPresent = true;
    parserData->pathPairTo = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1042:

    {
    if (parserData->pathPairMakeCopyPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one \"makeCopy\" attribute allowed");
    parserData->pathPairMakeCopyPresent = true;
    parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1045:

    {   
    if (parserData->categoryAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one category attribute allowed for this element");
    parserData->categoryAttributePresent = true;
}
    break;

  case 1048:

    { 
    parserData->categoryAttribute = "";
}
    break;

  case 1049:

    { 
    parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1050:

    {   if (parserData->conTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one conType attribute allowed for this element");
            parserData->conTypeAttributePresent = true;
        }
    break;

  case 1053:

    { parserData->conTypeAttribute = ""; }
    break;

  case 1054:

    { 
    parserData->conTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1055:

    {
    if (parserData->descriptionAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one description attribute allowed for this element");
    parserData->descriptionAttributePresent = true;
}
    break;

  case 1058:

    { parserData->descriptionAttribute = ""; }
    break;

  case 1059:

    { 
    parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1060:

    {   if (parserData->enumTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one enumType attribute allowed for this element");
            parserData->enumTypeAttributePresent = true;
        }
    break;

  case 1063:

    { parserData->enumTypeAttribute = ""; }
    break;

  case 1064:

    { 
    parserData->enumTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1065:

    {
    if (parserData->groupWeightAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one groupWeight attribute allowed for this element");
    parserData->groupWeightAttributePresent = true;
}
    break;

  case 1066:

    {
    parserData->groupWeight = parserData->tempVal;
}
    break;

  case 1067:

    {   
    if (parserData->idxAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one idx attribute allowed for this element");
    parserData->idxAttributePresent = true;
}
    break;

  case 1069:

    { 
    parserData->idxAttribute = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1070:

    {   
    if (parserData->lbValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one lb attribute allowed for this element");
    parserData->lbValueAttributePresent = true;
}
    break;

  case 1073:

    { 
    parserData->lbValueAttribute = ""; 
}
    break;

  case 1074:

    { 
    parserData->lbValueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1075:

    {   if (parserData->lbValueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one lb attribute allowed for this element");
            parserData->lbValueAttributePresent = true;
        }
    break;

  case 1078:

    { 
    parserData->lbDualValue = 0.0; 
}
    break;

  case 1079:

    {
    parserData->lbDualValue = parserData->tempVal;
}
    break;

  case 1080:

    {
        if (parserData->nameAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one name attribute allowed for this element");
        parserData->nameAttributePresent = true;
    }
    break;

  case 1083:

    { 
        parserData->nameAttribute = ""; 
    }
    break;

  case 1084:

    { 
        parserData->nameAttribute = (yyvsp[(2) - (3)].sval); 
        free((yyvsp[(2) - (3)].sval));
    }
    break;

  case 1085:

    {   if (parserData->objTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one objType attribute allowed for this element");
            parserData->objTypeAttributePresent = true;
        }
    break;

  case 1088:

    { parserData->objTypeAttribute = ""; }
    break;

  case 1089:

    { 
    parserData->objTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1090:

    {   if (parserData->solverAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one solver attribute allowed for this element");
        parserData->solverAttributePresent = true;
    }
    break;

  case 1093:

    { parserData->solverAttribute = ""; }
    break;

  case 1094:

    { 
    parserData->solverAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1095:

    {   if (parserData->sosIdxAttributePresent ) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one sosIdx attribute allowed for this element");
        parserData->sosIdxAttributePresent = true;
    }
    break;

  case 1097:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "SOS index must be nonnegative");
    parserData->sosIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1098:

    {   if (parserData->typeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one type attribute allowed for this element");
            parserData->typeAttributePresent = true;
        }
    break;

  case 1101:

    { parserData->typeAttribute = ""; }
    break;

  case 1102:

    { 
    parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1103:

    {
   if (parserData->ubValueAttributePresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one ub attribute allowed for this element");
    parserData->ubValueAttributePresent = true;
}
    break;

  case 1106:

    { 
    parserData->ubValueAttribute = ""; 
}
    break;

  case 1107:

    { 
    parserData->ubValueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1108:

    {   if (parserData->ubValueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one ub attribute allowed for this element");
            parserData->ubValueAttributePresent = true;
        }
    break;

  case 1111:

    { parserData->ubDualValue = 0.0; }
    break;

  case 1112:

    { 
    parserData->ubDualValue = parserData->tempVal;
}
    break;

  case 1113:

    {   if (parserData->unitAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one unit attribute allowed for this element");
            parserData->unitAttributePresent = true;
        }
    break;

  case 1116:

    { parserData->unitAttribute = ""; }
    break;

  case 1117:

    { 
    parserData->unitAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1118:

    {   if (parserData->valueAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one value attribute allowed for this element");
            parserData->valueAttributePresent = true;
        }
    break;

  case 1121:

    { parserData->valueAttribute = ""; }
    break;

  case 1122:

    {
    parserData->valueAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1123:

    {   if (parserData->varTypeAttributePresent ) 
                parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one varType attribute allowed for this element");
            parserData->varTypeAttributePresent = true;
        }
    break;

  case 1126:

    { parserData->varTypeAttribute = ""; }
    break;

  case 1127:

    { 
    parserData->varTypeAttribute = (yyvsp[(2) - (3)].sval); 
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1128:

    {
    if (parserData->numberOfConAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfCon attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <con> cannot be negative");
    parserData->numberOfConAttributePresent = true;        
    parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1129:

    {
    if (parserData->numberOfConstraintsPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfConstraints attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of constraints cannot be negative");
    parserData->numberOfConstraintsPresent = true;        
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1130:

    {
    if (osglData->osglNumberOfElPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfEl attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <el> cannot be negative");
    osglData->osglNumberOfElPresent = true;
    parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1131:

    {
    if (parserData->numberOfEnumerationsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfEnumerations attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <enumeration> elements cannot be negative");
    parserData->numberOfEnumerationsAttributePresent = true;        
    parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1132:

    {    
   if (parserData->numberOfItemsPresent ) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one numberOfItems attribute allowed");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of items cannot be negative");
    parserData->numberOfItemsPresent = true;
    parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1133:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of job IDs cannot be negative");
    else
        parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 1134:

    {
    if (parserData->numberOfObjAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfObj attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <obj> cannot be negative");
    parserData->numberOfObjAttributePresent = true;        
    parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1135:

    {
    if (parserData->numberOfObjectivesPresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfObjectives attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of objectives cannot be negative");
    parserData->numberOfObjectivesPresent = true;
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1136:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other constraint options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1137:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other objective options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1138:

    {
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1139:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of other variable options cannot be negative");
    parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1140:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of path pairs cannot be negative");
    else if ((yyvsp[(3) - (4)].ival) > 0)
    {
        parserData->fromPaths = new std::string[(yyvsp[(3) - (4)].ival)];
        parserData->toPaths   = new std::string[(yyvsp[(3) - (4)].ival)];
        parserData->makeCopy  = new bool[(yyvsp[(3) - (4)].ival)];
    }
    parserData->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 1141:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of paths cannot be negative");
    else
        parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 1142:

    {
    if ((yyvsp[(3) - (4)].ival) < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Number of job IDs cannot be negative");
    else
        parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
    parserData->numberOf = (yyvsp[(3) - (4)].ival);
    parserData->kounter = 0;
}
    break;

  case 1143:

    {    
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of solver options cannot be negative");
    parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1144:

    {
    if (parserData->numberOfVarAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVar attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of <var> cannot be negative");
    parserData->numberOfVarAttributePresent = true;        
    parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1145:

    {    if (parserData->numberOfVariablesPresent)

        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "numberOfVariables attribute previously set");
    if ((yyvsp[(3) - (4)].ival) < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "number of variables cannot be negative");
    parserData->numberOfVariablesPresent = true;    
    parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1148:

    {     
    if (!parserData->ignoreDataAfterErrors)
        if (!osoption->setOtherOptionEnumeration(parserData->otherOptionType, 
                parserData->iOther,
                parserData->kounter,
                osglData->osglNumberOfEl, 
                parserData->valueAttribute, 
                parserData->descriptionAttribute, 
                osglData->osglIntArray) )
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "set <other> option enumeration failed");

    delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
    osglData->osglNumberOfEl = 0;
    parserData->kounter++;
}
    break;

  case 1149:

    {
    if (parserData->kounter >= parserData->numberOfEnumerations)
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more <enumeration> elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    osglData->osglNumberOfElPresent = false;
    parserData->valueAttributePresent = false;
    parserData->descriptionAttributePresent = false;
    parserData->valueAttribute = "";
    parserData->descriptionAttribute = "";
}
    break;

  case 1150:

    {
        if(!osglData->osglNumberOfElPresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element enumeration requires numberOfEl attribute"); 
        if(!parserData->valueAttributePresent) 
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "<other> element enumeration requires value attribute"); 
    }
    break;

  case 1153:

    {
        osglData->osglCounter = 0; 
        osglData->osglNumberOfElPresent = true;
        osglData->osglNumberOfEl = parserData->numberOf;
        osglData->osglIntArray = new int[parserData->numberOf];
    }
    break;

  case 1161:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1162:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;

  case 1171:

    {
    osglData->fileName    = "";
    osglData->source      = "";
    osglData->description = "";
    osglData->fileCreator = "";
    osglData->licence     = "";
    osglData->fileNamePresent    = false;
    osglData->sourcePresent      = false;
    osglData->descriptionPresent = false;
    osglData->fileCreatorPresent = false;
    osglData->licencePresent     = false;
}
    break;

  case 1186:

    {
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
}
    break;

  case 1191:

    {
    osglData->fileName = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1193:

    {
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
}
    break;

  case 1198:

    {
    osglData->source = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1200:

    {
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
}
    break;

  case 1205:

    {
    osglData->description = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1207:

    {
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
}
    break;

  case 1212:

    {
    osglData->fileCreator = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1214:

    {
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
}
    break;

  case 1219:

    {
    osglData->licence = (yyvsp[(2) - (3)].sval);
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1220:

    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
    break;

  case 1225:

    {    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
}
    break;

  case 1231:

    {
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->osglMult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;    
}
    break;

  case 1233:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1238:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
    else
    {
        intvec = (int*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
        {
            osglData->osglIntArray[i] = *(intvec++);
        }
    }
    //delete[] b64string;
    free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1239:

    {    
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1240:

    {    
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "only one mult attribute allowed");
    if ((yyvsp[(3) - (4)].ival) <= 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1241:

    {
    osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1246:

    {
    char* b64string = (yyvsp[(2) - (3)].sval);
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    double *dblvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, osnlData, "base 64 data length does not match numberOfEl"); 
    else
    {
        dblvec = (double*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
        {
            osglData->osglDblArray[i] = *(dblvec++);
        }
    }
    //delete[] b64string;
    free((yyvsp[(2) - (3)].sval));
}
    break;



      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, osoption, parserData, osglData, osnlData, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (&yylloc, osoption, parserData, osglData, osnlData, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, osoption, parserData, osglData, osnlData, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc, osoption, parserData, osglData, osnlData);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, osoption, parserData, osglData, osnlData);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, osoption, parserData, osglData, osnlData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, osoption, parserData, osglData, osnlData);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, osoption, parserData, osglData, osnlData);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}





#if 0
void addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, const char* errormsg )
{
    osol_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    std::ostringstream outStr;
    std::string error = errormsg;
    error = "OSoL input is either not valid or well formed: "  + error;
    outStr << error << std::endl;
    outStr << "Error occurred when reading: " << osolget_text ( scanner ) << std::endl; 
    outStr << "See line number: " << osolget_lineno( scanner) << std::endl; 
    error = outStr.str();

} //end addErrorMsg
#endif

std::string addErrorMsg(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg )
{
    std::ostringstream outStr;
    outStr << "At line number " << osolget_lineno( scanner) << ": "; 
    outStr << osolget_text ( scanner ) << std::endl; 
    outStr << errormsg << std::endl;

    return outStr.str();
} //end addErrorMsg

void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, OSnLParserData *osnlData, std::string errormsg )
{
    osol_empty_vectors( parserData);
    osgl_empty_vectors( osglData);
    osnl_empty_vectors( osnlData);
    throw ErrorClass( errormsg);
} //end osolerror

void  yygetOSOption(const char *parsestring, OSOption *osoption, 
      OSoLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData) throw(ErrorClass)
{
    try{
        osol_scan_string( parsestring, scanner);
        osolset_lineno (1 , scanner );
        //
        // call the Bison parser
        //
        if(  osolparse( osoption,  parserData, osglData, osnlData) != 0) {
            //osollex_destroy(scanner);
              throw ErrorClass(  "Error parsing the OSoL file");
         }
    }
    catch(const ErrorClass& eclass){
        throw ErrorClass(  eclass.errormsg); 
    }
} //end yygetOSOption


void osol_empty_vectors( OSoLParserData* parserData){
/*
    int k;
    int numOtherVarVec = parserData->otherVarVec.size();
   
    for( k = 0; k < numOtherVarVec; k++){
        if( (parserData->otherVarVec[ k]  != NULL) && (parserData->otherVarVec[ k]->otherVarText != NULL) ) 
            delete[] parserData->otherVarVec[ k]->otherVarText;
        if( (parserData->otherVarVec[ k]  != NULL) && (parserData->otherVarVec[ k]->otherVarIndex != NULL) ) 
            delete[] parserData->otherVarVec[ k]->otherVarIndex;
            
        if( parserData->otherVarVec[ k]  != NULL) delete parserData->otherVarVec[ k];
    }

      parserData->otherVarVec.clear(); 
      
      int numDualVals =  parserData->dualVals.size();
      for(k = 0; k < numDualVals; k++){
          if( parserData->dualVals[ k]  != NULL  ) 
            delete parserData->dualVals[ k];
      }
      parserData->dualVals.clear();
      
      
       int numObjVals =  parserData->objVals.size();
      for(k = 0; k < numObjVals; k++){
          if( parserData->objVals[ k]  != NULL  ) 
            delete parserData->objVals[ k];
      }
      parserData->objVals.clear();
      
      
       int numPrimalVals =  parserData->primalVals.size();
      for(k = 0; k < numPrimalVals; k++){    
          if( parserData->primalVals[ k]  != NULL  ) 
            delete parserData->primalVals[ k];
      }
      parserData->primalVals.clear();
*/      
}//end osol_empty_vectors


