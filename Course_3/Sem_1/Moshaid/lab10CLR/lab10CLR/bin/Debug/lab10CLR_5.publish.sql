/*
Скрипт развертывания для lab10CLR

Этот код был создан программным средством.
Изменения, внесенные в этот файл, могут привести к неверному выполнению кода и будут потеряны
в случае его повторного формирования.
*/

GO
SET ANSI_NULLS, ANSI_PADDING, ANSI_WARNINGS, ARITHABORT, CONCAT_NULL_YIELDS_NULL, QUOTED_IDENTIFIER ON;

SET NUMERIC_ROUNDABORT OFF;


GO
:setvar DatabaseName "lab10CLR"
:setvar DefaultFilePrefix "lab10CLR"
:setvar DefaultDataPath "D:\Db\"
:setvar DefaultLogPath "D:\Db\"

GO
:on error exit
GO
/*
Проверьте режим SQLCMD и отключите выполнение скрипта, если режим SQLCMD не поддерживается.
Чтобы повторно включить скрипт после включения режима SQLCMD выполните следующую инструкцию:
SET NOEXEC OFF; 
*/
:setvar __IsSqlCmdEnabled "True"
GO
IF N'$(__IsSqlCmdEnabled)' NOT LIKE N'True'
    BEGIN
        PRINT N'Для успешного выполнения этого скрипта должен быть включен режим SQLCMD.';
        SET NOEXEC ON;
    END


GO
USE [$(DatabaseName)];


GO
PRINT N'Идет создание Определяемый пользователем тип [dbo].[PassportData]…';


GO
CREATE TYPE [dbo].[PassportData]
     EXTERNAL NAME [lab10CLR].[PassportData];


GO
PRINT N'Идет создание Функция [dbo].[CalculateAverageWithoutx]…';


GO
CREATE FUNCTION [dbo].[CalculateAverageWithoutx]
(@values NVARCHAR (MAX) NULL)
RETURNS FLOAT (53)
AS
 EXTERNAL NAME [lab10CLR].[UserDefinedFunctions].[CalculateAverageWithoutx]


GO
PRINT N'Идет создание Процедура [dbo].[CalculateAverageWithoutMinMax]…';


GO
CREATE PROCEDURE [dbo].[CalculateAverageWithoutMinMax]
@values NVARCHAR (MAX) NULL, @result FLOAT (53) NULL OUTPUT
AS EXTERNAL NAME [lab10CLR].[StoredProcedures].[CalculateAverageWithoutMinMax]


GO
PRINT N'Обновление завершено.';


GO
