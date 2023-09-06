use master
go

create database H_MyBase_H
    on primary
    (name = N'H_MyBase_mdf', filename = N'E:\DB\H_MyBase_mdf.mdf',
        size = 10240 Kb, maxsize = UNLIMITED, filegrowth =1024 Kb),

    ( name = N'H_MyBase_ndf', filename = N'E:\DB\H_MyBase_ndf.ndf',
        size = 10240 KB, maxsize =1 Gb, filegrowth =25%),

    filegroup FG1

        ( name = N'H_MyBase_fg1_1', filename = N'E:\DB\H_MyBase__fgq-1.ndf',
            size = 10240 Kb, maxsize =1 Gb, filegrowth =25%),
        ( name = N'H_MyBase_fg1_2', filename = N'E:\DB\H_MyBase_fgq-2.ndf',
            size = 10240 Kb, maxsize =1 Gb, filegrowth =25%)
    log on
    (name = N'H_MyBase_log', filename = N'E:\DB\H_MyBase_log.ldf',
        size = 10240 Kb, maxsize =2048 Gb, filegrowth =10%)
