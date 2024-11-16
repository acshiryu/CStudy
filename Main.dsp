# Microsoft Developer Studio Project File - Name="Main" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Main - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Main.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Main.mak" CFG="Main - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Main - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Main - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Main - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Main - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ./Recommend/Debug/Recommend.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Main - Win32 Release"
# Name "Main - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AddOpDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddTitleDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddWA.cpp
# End Source File
# Begin Source File

SOURCE=.\BCMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\BtnST.cpp
# End Source File
# Begin Source File

SOURCE=.\ChoiceQue.cpp
# End Source File
# Begin Source File

SOURCE=.\HOpQue.cpp
# End Source File
# Begin Source File

SOURCE=.\IpDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Main.cpp
# End Source File
# Begin Source File

SOURCE=.\Main.rc
# End Source File
# Begin Source File

SOURCE=.\MainDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\NxtSelectDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\OpAnsDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PointDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RegisterDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\student.cpp
# End Source File
# Begin Source File

SOURCE=.\SubmitDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TransparentStatic.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AddOpDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddTitleDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddWA.h
# End Source File
# Begin Source File

SOURCE=.\BCMenu.h
# End Source File
# Begin Source File

SOURCE=.\BtnST.h
# End Source File
# Begin Source File

SOURCE=.\ChoiceQue.h
# End Source File
# Begin Source File

SOURCE=.\HOpQue.h
# End Source File
# Begin Source File

SOURCE=.\IpDlg.h
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.h
# End Source File
# Begin Source File

SOURCE=.\Main.h
# End Source File
# Begin Source File

SOURCE=.\MainDlg.h
# End Source File
# Begin Source File

SOURCE=.\NxtSelectDlg.h
# End Source File
# Begin Source File

SOURCE=.\OpAnsDlg.h
# End Source File
# Begin Source File

SOURCE=.\PointDlg.h
# End Source File
# Begin Source File

SOURCE=.\RegisterDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\student.h
# End Source File
# Begin Source File

SOURCE=.\TransparentStatic.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Mainfrm\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\ChoiceAnsNo.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\ChoiceAnswer.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\ChoiceAnswerDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\ChoiceAnsYes.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\Close.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\CloseDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LOGO\cslogo.bmp
# End Source File
# Begin Source File

SOURCE=.\res\LOGO\cslogo2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Cursor\Hand.cur
# End Source File
# Begin Source File

SOURCE=.\res\Main.ico
# End Source File
# Begin Source File

SOURCE=.\res\Main.rc2
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\MainFrm.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\MainFrm2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\MainMenu1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\MainMenu1DOWN.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\MainMenu2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\MainMenu2DOWN.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\MainMenu3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\MainMenu3DOWN.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\MainMenu4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\MainMenu4DOWN.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\Min.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ICO\min.ico
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\MinDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\ICO\mindown.ico
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\NewButton.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\NewButtonDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\NextDlg.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\NextDlgDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonAbout.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonAboutDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonAdd.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonAddDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonCantactDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonCatact.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonCheck.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonCheckDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonChoice.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonChoiceDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonContact.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonContactDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonContinue.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonContinueDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonExam.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonExamDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonOperating.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonOperatingDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonSetting.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonSettingDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonThanks.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonThanksDown.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonWrongQue.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Mainfrm\SonWrongQueDown.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\res\LOGO\cslogo.png
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
