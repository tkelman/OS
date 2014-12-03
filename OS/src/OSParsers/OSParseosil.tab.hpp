
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     QUOTE = 258,
     ATTRIBUTETEXT = 259,
     ELEMENTTEXT = 260,
     ITEMTEXT = 261,
     INTEGER = 262,
     DOUBLE = 263,
     TWOQUOTES = 264,
     ENDOFELEMENT = 265,
     GREATERTHAN = 266,
     OSILEND = 267,
     INSTANCEDATAEND = 268,
     INSTANCEDATASTARTEND = 269,
     EMPTYIDATT = 270,
     IDXONEATT = 271,
     IDXTWOATT = 272,
     VALUEATT = 273,
     QUADRATICCOEFFICIENTSSTART = 274,
     QUADRATICCOEFFICIENTSEND = 275,
     NUMBEROFQTERMSATT = 276,
     QTERMSTART = 277,
     QTERMEND = 278,
     MATRICESSTART = 279,
     MATRICESEND = 280,
     NUMBEROFMATRICESATT = 281,
     CONESSTART = 282,
     CONESEND = 283,
     NUMBEROFCONESATT = 284,
     NONNEGATIVECONESTART = 285,
     NONNEGATIVECONEEND = 286,
     NONPOSITIVECONESTART = 287,
     NONPOSITIVECONEEND = 288,
     ORTHANTCONESTART = 289,
     ORTHANTCONEEND = 290,
     POLYHEDRALCONESTART = 291,
     POLYHEDRALCONEEND = 292,
     QUADRATICCONESTART = 293,
     QUADRATICCONEEND = 294,
     ROTATEDQUADRATICCONESTART = 295,
     ROTATEDQUADRATICCONEEND = 296,
     SEMIDEFINITECONESTART = 297,
     SEMIDEFINITECONEEND = 298,
     PRODUCTCONESTART = 299,
     PRODUCTCONEEND = 300,
     INTERSECTIONCONESTART = 301,
     INTERSECTIONCONEEND = 302,
     DUALCONESTART = 303,
     DUALCONEEND = 304,
     POLARCONESTART = 305,
     POLARCONEEND = 306,
     FACTORSSTART = 307,
     FACTORSEND = 308,
     COMPONENTSSTART = 309,
     COMPONENTSEND = 310,
     NORMSCALEFACTORATT = 311,
     DISTORTIONMATRIXIDXATT = 312,
     AXISDIRECTIONATT = 313,
     FIRSTAXISDIRECTIONATT = 314,
     SECONDAXISDIRECTIONATT = 315,
     EMPTYSEMIDEFINITENESSATT = 316,
     SEMIDEFINITENESSATT = 317,
     REFERENCEMATRIXIDXATT = 318,
     MATRIXPROGRAMMINGSTART = 319,
     MATRIXPROGRAMMINGEND = 320,
     VARTYPEATT = 321,
     MATRIXVARIABLESSTART = 322,
     MATRIXVARIABLESEND = 323,
     NUMBEROFMATRIXVARATT = 324,
     MATRIXVARSTART = 325,
     MATRIXVAREND = 326,
     MATRIXOBJECTIVESSTART = 327,
     MATRIXOBJECTIVESEND = 328,
     NUMBEROFMATRIXOBJATT = 329,
     MATRIXOBJSTART = 330,
     MATRIXOBJEND = 331,
     MATRIXCONSTRAINTSSTART = 332,
     MATRIXCONSTRAINTSEND = 333,
     NUMBEROFMATRIXCONATT = 334,
     MATRIXCONSTART = 335,
     MATRIXCONEND = 336,
     MATRIXIDXATT = 337,
     LBMATRIXIDXATT = 338,
     LBCONEIDXATT = 339,
     UBMATRIXIDXATT = 340,
     UBCONEIDXATT = 341,
     TEMPLATEMATRIXIDXATT = 342,
     VARREFERENCEMATRIXIDXATT = 343,
     OBJREFERENCEMATRIXIDXATT = 344,
     CONREFERENCEMATRIXIDXATT = 345,
     ORDERCONEIDXATT = 346,
     CONSTANTMATRIXIDXATT = 347,
     TIMEDOMAINSTART = 348,
     TIMEDOMAINEND = 349,
     STAGESSTART = 350,
     STAGESEND = 351,
     STAGESTART = 352,
     STAGEEND = 353,
     NUMBEROFSTAGESATT = 354,
     HORIZONATT = 355,
     STARTATT = 356,
     VARIABLESSTART = 357,
     CONSTRAINTSSTART = 358,
     OBJECTIVESSTART = 359,
     VARIABLESEND = 360,
     CONSTRAINTSEND = 361,
     OBJECTIVESEND = 362,
     NUMBEROFVARIABLESATT = 363,
     NUMBEROFCONSTRAINTSATT = 364,
     NUMBEROFOBJECTIVESATT = 365,
     STARTIDXATT = 366,
     VARSTART = 367,
     VAREND = 368,
     CONSTART = 369,
     CONEND = 370,
     OBJSTART = 371,
     OBJEND = 372,
     INTERVALSTART = 373,
     INTERVALEND = 374,
     HEADERSTART = 375,
     HEADEREND = 376,
     FILENAMESTART = 377,
     FILENAMEEND = 378,
     FILENAMEEMPTY = 379,
     FILENAMESTARTANDEND = 380,
     FILESOURCESTART = 381,
     FILESOURCEEND = 382,
     FILESOURCEEMPTY = 383,
     FILESOURCESTARTANDEND = 384,
     FILEDESCRIPTIONSTART = 385,
     FILEDESCRIPTIONEND = 386,
     FILEDESCRIPTIONEMPTY = 387,
     FILEDESCRIPTIONSTARTANDEND = 388,
     FILECREATORSTART = 389,
     FILECREATOREND = 390,
     FILECREATOREMPTY = 391,
     FILECREATORSTARTANDEND = 392,
     FILELICENCESTART = 393,
     FILELICENCEEND = 394,
     FILELICENCEEMPTY = 395,
     FILELICENCESTARTANDEND = 396,
     ENUMERATIONSTART = 397,
     ENUMERATIONEND = 398,
     NUMBEROFELATT = 399,
     ITEMEMPTY = 400,
     ITEMSTART = 401,
     ITEMEND = 402,
     ITEMSTARTANDEND = 403,
     BASE64START = 404,
     BASE64END = 405,
     INCRATT = 406,
     MULTATT = 407,
     SIZEOFATT = 408,
     ELSTART = 409,
     ELEND = 410,
     MATRIXSTART = 411,
     MATRIXEND = 412,
     BASEMATRIXEND = 413,
     BASEMATRIXSTART = 414,
     BLOCKSTART = 415,
     BLOCKEND = 416,
     BLOCKSSTART = 417,
     BLOCKSEND = 418,
     EMPTYNAMEATT = 419,
     NAMEATT = 420,
     EMPTYTYPEATT = 421,
     TYPEATT = 422,
     EMPTYSHAPEATT = 423,
     SHAPEATT = 424,
     EMPTYSYMMETRYATT = 425,
     SYMMETRYATT = 426,
     EMPTYNEGATIVEPATTERNATT = 427,
     NEGATIVEPATTERNATT = 428,
     CONSTANTATT = 429,
     NUMBEROFBLOCKSATT = 430,
     NUMBEROFCOLUMNSATT = 431,
     NUMBEROFROWSATT = 432,
     NUMBEROFVALUESATT = 433,
     NUMBEROFVARIDXATT = 434,
     IDXATT = 435,
     COEFATT = 436,
     BASEMATRIXIDXATT = 437,
     TARGETMATRIXFIRSTROWATT = 438,
     TARGETMATRIXFIRSTCOLATT = 439,
     BASEMATRIXSTARTROWATT = 440,
     BASEMATRIXSTARTCOLATT = 441,
     BASEMATRIXENDROWATT = 442,
     BASEMATRIXENDCOLATT = 443,
     SCALARMULTIPLIERATT = 444,
     EMPTYBASETRANSPOSEATT = 445,
     BASETRANSPOSEATT = 446,
     ELEMENTSSTART = 447,
     ELEMENTSEND = 448,
     CONSTANTELEMENTSSTART = 449,
     CONSTANTELEMENTSEND = 450,
     STARTVECTORSTART = 451,
     STARTVECTOREND = 452,
     NONZEROSSTART = 453,
     NONZEROSEND = 454,
     INDEXESSTART = 455,
     INDEXESEND = 456,
     VALUESSTART = 457,
     VALUESEND = 458,
     VARREFERENCEELEMENTSSTART = 459,
     VARREFERENCEELEMENTSEND = 460,
     LINEARELEMENTSSTART = 461,
     LINEARELEMENTSEND = 462,
     GENERALELEMENTSSTART = 463,
     GENERALELEMENTSEND = 464,
     CONREFERENCEELEMENTSSTART = 465,
     CONREFERENCEELEMENTSEND = 466,
     OBJREFERENCEELEMENTSSTART = 467,
     OBJREFERENCEELEMENTSEND = 468,
     PATTERNELEMENTSSTART = 469,
     PATTERNELEMENTSEND = 470,
     VARIDXSTART = 471,
     VARIDXEND = 472,
     TRANSFORMATIONSTART = 473,
     TRANSFORMATIONEND = 474,
     COLOFFSETSSTART = 475,
     COLOFFSETSEND = 476,
     ROWOFFSETSSTART = 477,
     ROWOFFSETSEND = 478,
     EMPTYROWMAJORATT = 479,
     ROWMAJORATT = 480,
     BLOCKROWIDXATT = 481,
     BLOCKCOLIDXATT = 482,
     DUMMY = 483,
     NONLINEAREXPRESSIONSSTART = 484,
     NONLINEAREXPRESSIONSEND = 485,
     NUMBEROFNONLINEAREXPRESSIONS = 486,
     NLSTART = 487,
     NLEND = 488,
     MATRIXEXPRESSIONSSTART = 489,
     MATRIXEXPRESSIONSEND = 490,
     NUMBEROFEXPR = 491,
     EXPRSTART = 492,
     EXPREND = 493,
     NUMBEROFMATRIXTERMSATT = 494,
     MATRIXTERMSTART = 495,
     MATRIXTERMEND = 496,
     POWERSTART = 497,
     POWEREND = 498,
     PLUSSTART = 499,
     PLUSEND = 500,
     MINUSSTART = 501,
     MINUSEND = 502,
     DIVIDESTART = 503,
     DIVIDEEND = 504,
     LNSTART = 505,
     LNEND = 506,
     SQRTSTART = 507,
     SQRTEND = 508,
     SUMSTART = 509,
     SUMEND = 510,
     PRODUCTSTART = 511,
     PRODUCTEND = 512,
     EXPSTART = 513,
     EXPEND = 514,
     NEGATESTART = 515,
     NEGATEEND = 516,
     IFSTART = 517,
     IFEND = 518,
     SQUARESTART = 519,
     SQUAREEND = 520,
     COSSTART = 521,
     COSEND = 522,
     SINSTART = 523,
     SINEND = 524,
     VARIABLESTART = 525,
     VARIABLEEND = 526,
     ABSSTART = 527,
     ABSEND = 528,
     ERFSTART = 529,
     ERFEND = 530,
     MAXSTART = 531,
     MAXEND = 532,
     ALLDIFFSTART = 533,
     ALLDIFFEND = 534,
     MINSTART = 535,
     MINEND = 536,
     ESTART = 537,
     EEND = 538,
     PISTART = 539,
     PIEND = 540,
     TIMESSTART = 541,
     TIMESEND = 542,
     NUMBERSTART = 543,
     NUMBEREND = 544,
     MATRIXDETERMINANTSTART = 545,
     MATRIXDETERMINANTEND = 546,
     MATRIXTRACESTART = 547,
     MATRIXTRACEEND = 548,
     MATRIXTOSCALARSTART = 549,
     MATRIXTOSCALAREND = 550,
     MATRIXDIAGONALSTART = 551,
     MATRIXDIAGONALEND = 552,
     MATRIXDOTTIMESSTART = 553,
     MATRIXDOTTIMESEND = 554,
     MATRIXLOWERTRIANGLESTART = 555,
     MATRIXLOWERTRIANGLEEND = 556,
     MATRIXUPPERTRIANGLESTART = 557,
     MATRIXUPPERTRIANGLEEND = 558,
     MATRIXMERGESTART = 559,
     MATRIXMERGEEND = 560,
     MATRIXMINUSSTART = 561,
     MATRIXMINUSEND = 562,
     MATRIXNEGATESTART = 563,
     MATRIXNEGATEEND = 564,
     MATRIXPLUSSTART = 565,
     MATRIXPLUSEND = 566,
     MATRIXTIMESSTART = 567,
     MATRIXTIMESEND = 568,
     MATRIXPRODUCTSTART = 569,
     MATRIXPRODUCTEND = 570,
     MATRIXSCALARTIMESSTART = 571,
     MATRIXSCALARTIMESEND = 572,
     MATRIXSUBMATRIXATSTART = 573,
     MATRIXSUBMATRIXATEND = 574,
     MATRIXTRANSPOSESTART = 575,
     MATRIXTRANSPOSEEND = 576,
     MATRIXREFERENCESTART = 577,
     MATRIXREFERENCEEND = 578,
     IDENTITYMATRIXSTART = 579,
     IDENTITYMATRIXEND = 580,
     MATRIXINVERSESTART = 581,
     MATRIXINVERSEEND = 582,
     EMPTYINCLUDEDIAGONALATT = 583,
     INCLUDEDIAGONALATT = 584,
     IDATT = 585
   };
#endif
/* Tokens.  */
#define QUOTE 258
#define ATTRIBUTETEXT 259
#define ELEMENTTEXT 260
#define ITEMTEXT 261
#define INTEGER 262
#define DOUBLE 263
#define TWOQUOTES 264
#define ENDOFELEMENT 265
#define GREATERTHAN 266
#define OSILEND 267
#define INSTANCEDATAEND 268
#define INSTANCEDATASTARTEND 269
#define EMPTYIDATT 270
#define IDXONEATT 271
#define IDXTWOATT 272
#define VALUEATT 273
#define QUADRATICCOEFFICIENTSSTART 274
#define QUADRATICCOEFFICIENTSEND 275
#define NUMBEROFQTERMSATT 276
#define QTERMSTART 277
#define QTERMEND 278
#define MATRICESSTART 279
#define MATRICESEND 280
#define NUMBEROFMATRICESATT 281
#define CONESSTART 282
#define CONESEND 283
#define NUMBEROFCONESATT 284
#define NONNEGATIVECONESTART 285
#define NONNEGATIVECONEEND 286
#define NONPOSITIVECONESTART 287
#define NONPOSITIVECONEEND 288
#define ORTHANTCONESTART 289
#define ORTHANTCONEEND 290
#define POLYHEDRALCONESTART 291
#define POLYHEDRALCONEEND 292
#define QUADRATICCONESTART 293
#define QUADRATICCONEEND 294
#define ROTATEDQUADRATICCONESTART 295
#define ROTATEDQUADRATICCONEEND 296
#define SEMIDEFINITECONESTART 297
#define SEMIDEFINITECONEEND 298
#define PRODUCTCONESTART 299
#define PRODUCTCONEEND 300
#define INTERSECTIONCONESTART 301
#define INTERSECTIONCONEEND 302
#define DUALCONESTART 303
#define DUALCONEEND 304
#define POLARCONESTART 305
#define POLARCONEEND 306
#define FACTORSSTART 307
#define FACTORSEND 308
#define COMPONENTSSTART 309
#define COMPONENTSEND 310
#define NORMSCALEFACTORATT 311
#define DISTORTIONMATRIXIDXATT 312
#define AXISDIRECTIONATT 313
#define FIRSTAXISDIRECTIONATT 314
#define SECONDAXISDIRECTIONATT 315
#define EMPTYSEMIDEFINITENESSATT 316
#define SEMIDEFINITENESSATT 317
#define REFERENCEMATRIXIDXATT 318
#define MATRIXPROGRAMMINGSTART 319
#define MATRIXPROGRAMMINGEND 320
#define VARTYPEATT 321
#define MATRIXVARIABLESSTART 322
#define MATRIXVARIABLESEND 323
#define NUMBEROFMATRIXVARATT 324
#define MATRIXVARSTART 325
#define MATRIXVAREND 326
#define MATRIXOBJECTIVESSTART 327
#define MATRIXOBJECTIVESEND 328
#define NUMBEROFMATRIXOBJATT 329
#define MATRIXOBJSTART 330
#define MATRIXOBJEND 331
#define MATRIXCONSTRAINTSSTART 332
#define MATRIXCONSTRAINTSEND 333
#define NUMBEROFMATRIXCONATT 334
#define MATRIXCONSTART 335
#define MATRIXCONEND 336
#define MATRIXIDXATT 337
#define LBMATRIXIDXATT 338
#define LBCONEIDXATT 339
#define UBMATRIXIDXATT 340
#define UBCONEIDXATT 341
#define TEMPLATEMATRIXIDXATT 342
#define VARREFERENCEMATRIXIDXATT 343
#define OBJREFERENCEMATRIXIDXATT 344
#define CONREFERENCEMATRIXIDXATT 345
#define ORDERCONEIDXATT 346
#define CONSTANTMATRIXIDXATT 347
#define TIMEDOMAINSTART 348
#define TIMEDOMAINEND 349
#define STAGESSTART 350
#define STAGESEND 351
#define STAGESTART 352
#define STAGEEND 353
#define NUMBEROFSTAGESATT 354
#define HORIZONATT 355
#define STARTATT 356
#define VARIABLESSTART 357
#define CONSTRAINTSSTART 358
#define OBJECTIVESSTART 359
#define VARIABLESEND 360
#define CONSTRAINTSEND 361
#define OBJECTIVESEND 362
#define NUMBEROFVARIABLESATT 363
#define NUMBEROFCONSTRAINTSATT 364
#define NUMBEROFOBJECTIVESATT 365
#define STARTIDXATT 366
#define VARSTART 367
#define VAREND 368
#define CONSTART 369
#define CONEND 370
#define OBJSTART 371
#define OBJEND 372
#define INTERVALSTART 373
#define INTERVALEND 374
#define HEADERSTART 375
#define HEADEREND 376
#define FILENAMESTART 377
#define FILENAMEEND 378
#define FILENAMEEMPTY 379
#define FILENAMESTARTANDEND 380
#define FILESOURCESTART 381
#define FILESOURCEEND 382
#define FILESOURCEEMPTY 383
#define FILESOURCESTARTANDEND 384
#define FILEDESCRIPTIONSTART 385
#define FILEDESCRIPTIONEND 386
#define FILEDESCRIPTIONEMPTY 387
#define FILEDESCRIPTIONSTARTANDEND 388
#define FILECREATORSTART 389
#define FILECREATOREND 390
#define FILECREATOREMPTY 391
#define FILECREATORSTARTANDEND 392
#define FILELICENCESTART 393
#define FILELICENCEEND 394
#define FILELICENCEEMPTY 395
#define FILELICENCESTARTANDEND 396
#define ENUMERATIONSTART 397
#define ENUMERATIONEND 398
#define NUMBEROFELATT 399
#define ITEMEMPTY 400
#define ITEMSTART 401
#define ITEMEND 402
#define ITEMSTARTANDEND 403
#define BASE64START 404
#define BASE64END 405
#define INCRATT 406
#define MULTATT 407
#define SIZEOFATT 408
#define ELSTART 409
#define ELEND 410
#define MATRIXSTART 411
#define MATRIXEND 412
#define BASEMATRIXEND 413
#define BASEMATRIXSTART 414
#define BLOCKSTART 415
#define BLOCKEND 416
#define BLOCKSSTART 417
#define BLOCKSEND 418
#define EMPTYNAMEATT 419
#define NAMEATT 420
#define EMPTYTYPEATT 421
#define TYPEATT 422
#define EMPTYSHAPEATT 423
#define SHAPEATT 424
#define EMPTYSYMMETRYATT 425
#define SYMMETRYATT 426
#define EMPTYNEGATIVEPATTERNATT 427
#define NEGATIVEPATTERNATT 428
#define CONSTANTATT 429
#define NUMBEROFBLOCKSATT 430
#define NUMBEROFCOLUMNSATT 431
#define NUMBEROFROWSATT 432
#define NUMBEROFVALUESATT 433
#define NUMBEROFVARIDXATT 434
#define IDXATT 435
#define COEFATT 436
#define BASEMATRIXIDXATT 437
#define TARGETMATRIXFIRSTROWATT 438
#define TARGETMATRIXFIRSTCOLATT 439
#define BASEMATRIXSTARTROWATT 440
#define BASEMATRIXSTARTCOLATT 441
#define BASEMATRIXENDROWATT 442
#define BASEMATRIXENDCOLATT 443
#define SCALARMULTIPLIERATT 444
#define EMPTYBASETRANSPOSEATT 445
#define BASETRANSPOSEATT 446
#define ELEMENTSSTART 447
#define ELEMENTSEND 448
#define CONSTANTELEMENTSSTART 449
#define CONSTANTELEMENTSEND 450
#define STARTVECTORSTART 451
#define STARTVECTOREND 452
#define NONZEROSSTART 453
#define NONZEROSEND 454
#define INDEXESSTART 455
#define INDEXESEND 456
#define VALUESSTART 457
#define VALUESEND 458
#define VARREFERENCEELEMENTSSTART 459
#define VARREFERENCEELEMENTSEND 460
#define LINEARELEMENTSSTART 461
#define LINEARELEMENTSEND 462
#define GENERALELEMENTSSTART 463
#define GENERALELEMENTSEND 464
#define CONREFERENCEELEMENTSSTART 465
#define CONREFERENCEELEMENTSEND 466
#define OBJREFERENCEELEMENTSSTART 467
#define OBJREFERENCEELEMENTSEND 468
#define PATTERNELEMENTSSTART 469
#define PATTERNELEMENTSEND 470
#define VARIDXSTART 471
#define VARIDXEND 472
#define TRANSFORMATIONSTART 473
#define TRANSFORMATIONEND 474
#define COLOFFSETSSTART 475
#define COLOFFSETSEND 476
#define ROWOFFSETSSTART 477
#define ROWOFFSETSEND 478
#define EMPTYROWMAJORATT 479
#define ROWMAJORATT 480
#define BLOCKROWIDXATT 481
#define BLOCKCOLIDXATT 482
#define DUMMY 483
#define NONLINEAREXPRESSIONSSTART 484
#define NONLINEAREXPRESSIONSEND 485
#define NUMBEROFNONLINEAREXPRESSIONS 486
#define NLSTART 487
#define NLEND 488
#define MATRIXEXPRESSIONSSTART 489
#define MATRIXEXPRESSIONSEND 490
#define NUMBEROFEXPR 491
#define EXPRSTART 492
#define EXPREND 493
#define NUMBEROFMATRIXTERMSATT 494
#define MATRIXTERMSTART 495
#define MATRIXTERMEND 496
#define POWERSTART 497
#define POWEREND 498
#define PLUSSTART 499
#define PLUSEND 500
#define MINUSSTART 501
#define MINUSEND 502
#define DIVIDESTART 503
#define DIVIDEEND 504
#define LNSTART 505
#define LNEND 506
#define SQRTSTART 507
#define SQRTEND 508
#define SUMSTART 509
#define SUMEND 510
#define PRODUCTSTART 511
#define PRODUCTEND 512
#define EXPSTART 513
#define EXPEND 514
#define NEGATESTART 515
#define NEGATEEND 516
#define IFSTART 517
#define IFEND 518
#define SQUARESTART 519
#define SQUAREEND 520
#define COSSTART 521
#define COSEND 522
#define SINSTART 523
#define SINEND 524
#define VARIABLESTART 525
#define VARIABLEEND 526
#define ABSSTART 527
#define ABSEND 528
#define ERFSTART 529
#define ERFEND 530
#define MAXSTART 531
#define MAXEND 532
#define ALLDIFFSTART 533
#define ALLDIFFEND 534
#define MINSTART 535
#define MINEND 536
#define ESTART 537
#define EEND 538
#define PISTART 539
#define PIEND 540
#define TIMESSTART 541
#define TIMESEND 542
#define NUMBERSTART 543
#define NUMBEREND 544
#define MATRIXDETERMINANTSTART 545
#define MATRIXDETERMINANTEND 546
#define MATRIXTRACESTART 547
#define MATRIXTRACEEND 548
#define MATRIXTOSCALARSTART 549
#define MATRIXTOSCALAREND 550
#define MATRIXDIAGONALSTART 551
#define MATRIXDIAGONALEND 552
#define MATRIXDOTTIMESSTART 553
#define MATRIXDOTTIMESEND 554
#define MATRIXLOWERTRIANGLESTART 555
#define MATRIXLOWERTRIANGLEEND 556
#define MATRIXUPPERTRIANGLESTART 557
#define MATRIXUPPERTRIANGLEEND 558
#define MATRIXMERGESTART 559
#define MATRIXMERGEEND 560
#define MATRIXMINUSSTART 561
#define MATRIXMINUSEND 562
#define MATRIXNEGATESTART 563
#define MATRIXNEGATEEND 564
#define MATRIXPLUSSTART 565
#define MATRIXPLUSEND 566
#define MATRIXTIMESSTART 567
#define MATRIXTIMESEND 568
#define MATRIXPRODUCTSTART 569
#define MATRIXPRODUCTEND 570
#define MATRIXSCALARTIMESSTART 571
#define MATRIXSCALARTIMESEND 572
#define MATRIXSUBMATRIXATSTART 573
#define MATRIXSUBMATRIXATEND 574
#define MATRIXTRANSPOSESTART 575
#define MATRIXTRANSPOSEEND 576
#define MATRIXREFERENCESTART 577
#define MATRIXREFERENCEEND 578
#define IDENTITYMATRIXSTART 579
#define IDENTITYMATRIXEND 580
#define MATRIXINVERSESTART 581
#define MATRIXINVERSEEND 582
#define EMPTYINCLUDEDIAGONALATT 583
#define INCLUDEDIAGONALATT 584
#define IDATT 585




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



