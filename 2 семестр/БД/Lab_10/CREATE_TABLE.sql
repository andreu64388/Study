CREATE TABLE FACULTY
  (
   FACULTY      CHAR(10)      NOT NULL,
   FACULTY_NAME VARCHAR2(60), 
   constraint pk_faculty primary key(faculty) 
  );
  
insert into FACULTY   (FACULTY,   FACULTY_NAME )
             values  ('IDiP',   'Izdatelskoye delo i poligraphiya');
insert into FACULTY   (FACULTY,   FACULTY_NAME )
            values  ('HTiT',   'Himicheskaya tehnologiya i tehnika');
insert into FACULTY   (FACULTY,   FACULTY_NAME )
            values  ('LHF',     'Lesohozyaystvenniy fakultet');
insert into FACULTY   (FACULTY,   FACULTY_NAME )
            values  ('IEF',     'inzhenerno-ekonomicheskiy fakultet');
insert into FACULTY   (FACULTY,   FACULTY_NAME )
            values  ('TTLP',    'Tehnologiya i tehnika lesnoy promishlennosti');
insert into faculty   (faculty,   faculty_name )
            values  ('TOV',     'Teknologiya organicheskih veschestv');
            
CREATE TABLE PULPIT 
(
 PULPIT       CHAR(10)      NOT NULL,
 PULPIT_NAME  VARCHAR2(100), 
 FACULTY      CHAR(10)      NOT NULL, 
 CONSTRAINT FK_PULPIT_FACULTY FOREIGN KEY(FACULTY)   REFERENCES FACULTY(FACULTY), 
 CONSTRAINT PK_PULPIT PRIMARY KEY(PULPIT) 
 ); 
 
insert into PULPIT   (PULPIT,    PULPIT_NAME, FACULTY )
             values  ('ISiT',    'Informatsionnih sistem i tehnologiy', 'IDiP'  );
insert into PULPIT   (PULPIT,    PULPIT_NAME, FACULTY )
             values  ('POiSOI', 'Poligraficheskogo oborudovaniya i sistem obrabotki informatsii', 'IDiP'  );
insert into PULPIT   (PULPIT,    PULPIT_NAME, FACULTY)
              values  ('LV',      'Lesovodstva', 'LHF') ;         
insert into pulpit   (pulpit,    pulpit_name, faculty)
             values  ('OV',      'Ohotovedeniya', 'LHF') ;   
insert into PULPIT   (PULPIT,    PULPIT_NAME, FACULTY)
             values  ('LU',      'Lesoustroystva', 'LHF');           
insert into pulpit   (pulpit,    pulpit_name, faculty)
             values  ('LZiDV',   'Lesozaschiti i drevesinovedeniya', 'LHF');                
insert into PULPIT   (PULPIT,    PULPIT_NAME, FACULTY)
             values  ('LPiSPS',  'Landshaftnogo proektirovaniya i sadovo-parkovogo stroitelstva','LHF');                  
insert into pulpit   (pulpit,    pulpit_name, faculty)
             values  ('TL',     'Transporta lesa', 'TTLP');                        
insert into PULPIT   (PULPIT,    PULPIT_NAME, FACULTY)
             values  ('LMiLZ',  'Lesnih mashin i tehnologiy lesozagotovok', 'TTLP');                        
insert into PULPIT   (PULPIT,    PULPIT_NAME,  FACULTY)
             values  ('OH',     'Organicheskoy himii', 'TOV');            
insert into PULPIT   (PULPIT,    PULPIT_NAME, FACULTY)
             values  ('TNHSiPPM','Tehnologii heftehimicheskogo sinteza i pererabotki polimernih materialov','TOV');             
insert into PULPIT   (PULPIT,    PULPIT_NAME,FACULTY)
             values  ('TNViONT','Tehnologii neorganicheskih veschestv i obschey himicheskoy tehnologii','HTiT');                    
insert into PULPIT   (PULPIT,    PULPIT_NAME, FACULTY)
             values  ('HTEPiMEE','Ximii, tehnologii elektrohimicheskih i materialov elektronnoy tehniki', 'HTiT');
insert into pulpit   (pulpit,    pulpit_name, faculty)
             values  ('ETiM',    'Ekonomicheskoy teorii i marketinga', 'IEF');   
insert into pulpit   (pulpit,    pulpit_name, faculty)
             values  ('MiEP',   'Menedzhmenta i ekonomiki polzovniya','IEF');

CREATE TABLE TEACHER
 ( 
  TEACHER       CHAR(10) NOT  NULL,
  TEACHER_NAME  VARCHAR2(50), 
  PULPIT        CHAR(10) NOT NULL, 
  CONSTRAINT PK_TEACHER  PRIMARY KEY(TEACHER), 
  constraint fk_teacher_pulpit foreign   key(pulpit)   references pulpit(pulpit)
 ) ;
 
insert into  TEACHER    (TEACHER,   TEACHER_NAME, PULPIT )
                       values  ('SMLV',    'Smelov Vladimir Vladislavovich',  'ISiT');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('AKNVCH',    'Akunovich Stanislav Ivanovich',  'ISiT');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('KLNSV',    'Kolesnikov Leonid Valerevich',  'ISiT');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('GRMN',    'German Oleg Vitoldovich',  'ISiT');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('LSCHNK',    'Laschenko Anatoliy Pavlovich',  'ISiT');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('BRKVCH',    'Brakovich Andrey Igorevich',  'ISiT');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('DDK',     'Dyadko Aleksandr Arkadievich',  'ISiT');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('KBL',     'Kabaylo Aleksandr Serafimovich',  'ISiT');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('URB',     'Urbanovich Pavel Pavlovich',  'ISiT');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('RMNK',     'Romanenko Dmitriy Mihaylovich',  'ISiT');
insert into  TEACHER    (TEACHER,  TEACHER_NSAME, PULPIT )
                       values  ('PSTVLV',  'Pustovalova Natalya Nikolaevna', 'ISiT' );
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                      values  ('GRN',     'Gurin Nikolay Ivanovich',  'ISiT');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('ZHLK',     'Zhilyak Nadezhda Aleksandrovna',  'ISiT');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('BRTSHVCH',   'Bartashevich Svyatoslav Aleksandrovich',  'POiSOI');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('YUDNKV',   'Yudenkov Viktor Stepanovich',  'POiSOI');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('BRNVSK',   'Baranovskiy Stanislav Ivanovich',  'ETiM');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('NVRV',   'Neverov Aleksandr Vasilievich',  'MiEP');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('RVKCH',   'Rovkach Andrey Ivanovich',  'OV');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('DMDK', 'Demidko Marina Nikovaevna',  'LPiSPS');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('MSHKVSK',   'Mashkovskiy Vladimir Petrovich',  'LU');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('LBH',   'Laboha Konstantin Valentinovich',  'LV');
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('ZVGTSV',   'Zvyagintsev Vacheslav Borisovich',  'LZiDV'); 
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('BZBRDV',   'Bexborodov Vladimir Stepanovich',  'OH'); 
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('PRKPCHK',   'Prokopchuk Nikolay Romanovich',  'TNHSiPPM'); 
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('NSKVTS',   'Naskovets Mikhail Trofimovich',  'TL'); 
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('MHV',   'Mohov Sergey Petrovich',  'LMiLZ'); 
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('ESCHNK',   'Eschenko Ludmila Semenovna',  'TNViONT'); 
insert into  TEACHER    (TEACHER,  TEACHER_NAME, PULPIT )
                       values  ('ZHRSK',   'Zharskiy Ivan Mihailovich',  'HTEPiMEE'); 

CREATE TABLE SUBJECT
    (
     SUBJECT      CHAR(10)     NOT NULL, 
     SUBJECT_NAME VARCHAR2(50)  NOT NULL,
     PULPIT       CHAR(10)     NOT NULL,  
     CONSTRAINT PK_SUBJECT PRIMARY KEY(SUBJECT),
     constraint fk_subject_pulpit foreign  key(pulpit)  references pulpit(pulpit)
    );

insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('SUBD',   'Sistemi upravleniya bazami dannih',                   'ISiT');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT)
                       values ('BD',     'Bazi dannih',                                        'ISiT');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('INF',    'Informatsionnie tehnologii',                          'ISiT');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('OAiP',  'Osnovi algoritmizatsii i programmirovaniya',            'ISiT');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('PZ',     'Predstavlenie znaniy v kompyuternih sistemah',       'ISiT');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('PSP',    'Programmirovanie setevih prilozheniy',                 'ISiT');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('MSOI',     'Modelirovanie sistem obrabotki informatsii',        'ISiT');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('PIS',     'Proektirovanie informatsionnih sistem',              'ISiT');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('KG',      'Komputernaya geometriya',                           'ISiT');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('PMAPL',   'Poligraficheskie mashini i potochnie linii', 'POiSOI');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('KMS',     'Komputernie multimediynie sistemi',               'ISiT');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('OPP',     'Organizatsiya poligraphicheskogo proizvodstva',         'POiSOI');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,                            PULPIT)
               values ('DM',   'Diskretnaya matematika',                     'ISiT');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,                             PULPIT )
               values ('MP',   'Matematicheskoe programmirovanie',          'ISiT');  
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,                             PULPIT )
               values ('LEVM', 'Logicheskie osnovi EVM',                     'ISiT');                   
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,                             PULPIT )
               values ('OOP',  'Obektno-orientirovannoe programmirovanie', 'ISiT');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('EP',     'Ekonomika prirodopolzovaniya',                       'MiEP');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('ET',     'Ekonomisheskaya teoriya',                               'ETiM');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('BLZiPsOO','Biologiya lesnih zverey i ptits',      'OV');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('OSPiLPH','Osnovi lesoparkovogo i cadoparkovogo hozyaystva',  'LPiSPS');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('IG',     'Inzhenernaya geodeziya',                              'LU');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('LV',    'Lesovodstvo',                                        'LZiDV');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('OH',    'Organicheskaya himiya',                                 'OH');   
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('TRI',    'Tehnologiya rezinovih izdeliy',                      'TNHSiPPM'); 
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('VTL',    'Vodniy transport lesa',                             'TL');
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('TiOL',   'Tehnologiya i oborudivanie lesozagotovok',           'LMiLZ'); 
insert into SUBJECT   (SUBJECT,   SUBJECT_NAME,        PULPIT )
                       values ('TOPI',   'Tehnologiya obogascheniya poleznikh iskopaemikh',        'TNViONT');
insert into subject   (subject,   subject_name,        pulpit )
                       values ('PEH',    'Prikladnaya elektrohimiya',                           'HTEPiMEE');   

create table AUDITORIUM_TYPE 
(
  AUDITORIUM_TYPE   char(10) constraint AUDITORIUM_TYPE_PK  primary key,  
  auditorium_typename  varchar2(30) constraint auditorium_typename_not_null not null         
);

insert into AUDITORIUM_TYPE   (AUDITORIUM_TYPE,   AUDITORIUM_TYPENAME )
                       values  ('LK',   'Lektsionnaya');
insert into AUDITORIUM_TYPE   (AUDITORIUM_TYPE,   AUDITORIUM_TYPENAME )
                       values  ('LB-K',   'Kompyuterniy klass');
insert into AUDITORIUM_TYPE   (AUDITORIUM_TYPE,   AUDITORIUM_TYPENAME )
                       values  ('LK-K', 'Lekts. s ustanovlennimi komp');
insert into AUDITORIUM_TYPE   (AUDITORIUM_TYPE,   AUDITORIUM_TYPENAME )
                       values  ('LB-H', 'Himicheskaya laboratoriya');
insert into auditorium_type   (auditorium_type,   auditorium_typename )
                       values  ('LB-SK', 'Spetsialniy komputerniy klass');
                       
create table AUDITORIUM 
(
 AUDITORIUM           char(10) primary key,  -- ??? ?????????
 AUDITORIUM_NAME      varchar2(200),          -- ????????? 
 AUDITORIUM_CAPACITY  number(4),              -- ???????????
 AUDITORIUM_TYPE      char(10) not null      -- ??? ?????????
                      references auditorium_type(auditorium_type)  
);

insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('206-1',   '206-1', 'LB-K', 15);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY)
                       values  ('301-1',   '301-1', 'LB-K', 15);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('236-1',   '236-1', 'LK',   60);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('313-1',   '313-1', 'LK',   60);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('324-1',   '324-1', 'LK',   50);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('413-1',   '413-1', 'LB-K', 15);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('423-1',   '423-1', 'LB-K', 90);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('408-2',   '408-2', 'LK',  90);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('103-4',   '103-4', 'LK',  90);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('105-4',   '105-4', 'LK',  90);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('107-4',   '107-4', 'LK',  90);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('110-4',   '110-4', 'LK',  30);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('111-4',   '111-4', 'LK',  30);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                      values  ('114-4',   '114-4', 'LK-K',  90 );
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values ('132-4',   '132-4', 'LK',   90);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values ('02?-4',   '02?-4', 'LK',   90);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values ('229-4',   '229-4', 'LK',   90);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('304-4',   '304-4','LB-K', 90);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('314-4',   '314-4', 'LK',  90);
insert into  AUDITORIUM   (AUDITORIUM,   AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY )
                       values  ('320-4',   '320-4', 'LK',  90);
insert into  auditorium   (auditorium,   auditorium_name, auditorium_type, auditorium_capacity )
                       values  ('429-4',   '429-4', 'LK',  90);
                       
                       
                       
                