;=================================================================== Test Cases/Test Data ========================================================================
; Critical (C)		:		Y
; TestCase No.		:		TS_TX_LIN_03
; TestCases			:		Transmitting Master frame
; Test Data			:
; Test Setup		:		1. Import LDF file
;							2. Select LIN->Transmit->Configure.
;							3. Select frames for transmission from dropdown Box provided in Tx frame List.(Add Message).
;							4. Connect

; Expected Results  : 		After step1, "Import LDF" window will open.
							;~ A dialog will open to select and associate a database.
							;~ And it should allow to select  LDF files of extension .ldf only.
							;~ After step2,a window should be displayed with the list of frames as given.
							;~ After step3, the selected frame should be displayed in the Tx frame list box
							;~ After step4, the frames configured should get transmitted.
							;~ If the Repetition cycle is specified then, according to the Repetition interval the header/master request is transmitted
							;~ Slave not responding event will be shown in message window (if response is not configured in Tx window)

;==========================================================================Test Procedure =========================================================================
ConsoleWrite(@CRLF)
ConsoleWrite("****Start : TS_TX_LIN_03****"&@CRLF)

Local $Timedelay=0,$VerifyMsg=1,$FirstMsg=0,$FirstMsgTime=0,$SecondMsgTime=0,$TimeDelay=0,$ErrMsg=0,$SecondMsg=0,$Tm2=0,$Tm1=0

_launchApp()

WinActivate($WIN_BUSMASTER)
Local $Time_cyclic=0,$a=0
if winexists($WIN_BUSMASTER) then


	_createConfig("TS_TX_LIN_03")
	;_SetViewToolBarLIN()																	 		; Select LIN Tool Bar to view.
	sleep(1000)
	;_linDriverSelectionXml()																 		; Select LIN driver selection from xml configuration File.
	_linDriverSelection()
	;_linDriverSelectionXml()																		; Select LIN driver selection from xml configuration File.
	sleep(1000)
	sleep(1000)
	_openLINClusterConfig()
	WinWaitActive($WIN_ClustrConfigLIN)
	if winexists($WIN_ClustrConfigLIN) then
		sleep(1000)
		_importLDF("TestLIN2_1.ldf")
		;_importLDF("LINALTECM_01-00.ldf")
		sleep(1000)
		ControlCommand($WIN_ClustrConfigLIN, "",$chckBoxEnableMaster, "Check", "") 					; Select Check box for enable Master mode.
		Sleep(1000)
		ControlClick($WIN_ClusterConfiguration,"",$BTN_OK_ClusterConfig)
		sleep(1000)
		_TxMsgMenuLIN()
		_ConfigTXWinDetails(0,"db",1,1,"","Master","",1000,"")										; $Rownum,$HSCaseNo("db","ndb"),$messageid/Index(For dbMessage),chnl,datalength,Messageype,RTR(Yes/No),Repetition,Key
		_ConfigTXWinDetails(1,"db",1,1,"","Slave","",1000,"")										; $Rownum,$HSCaseNo("db","ndb"),$messageid/Index(For dbMessage),chnl,datalength,Messageype,RTR(Yes/No),Repetit
		_CloseTxWindowArg("LIN")																	; Close Tx window
		_ConnectDisconnect_LIN()
		sleep(1000)
		_ConnectDisconnect_LIN()
		;_CloseTxWindowArg("LIN")																	; Close Tx window
	EndIf

	_DisableOverwriteModeAll($linMenu)
	$rCount=_GetLINMsgWinItemCount()																;count no. of items in msgwindow
	$CountCol=_GetLINMsgWinColCount()																;count no. of columns in msgwindow
	ConsoleWrite("$rCount="&$rCount&@CRLF)
	ConsoleWrite("$Count1="&$CountCol&@CRLF)


	Local $Msg0 = ObjCreate("System.Collections.ArrayList") 										; create object
	Local $Msg1 = ObjCreate("System.Collections.ArrayList") 										; create object

	if $rCount >= 2 Then
		$Msg0=_GetMsgWinInfo($LVC_CID_LINMsgWin,0,10)												; Fetch the first row data in the msg window
		$Msg1=_GetMsgWinInfo($LVC_CID_LINMsgWin,1,10)
		sleep(2000)
		;if $Msg0.Item(0) <>" " and $Msg0.Item(1)="Frame1" and $Msg0.Item(2)="LIN Message" and $Msg0.Item(3)="Tx" and $Msg0.Item(4)=1 and $Msg0.Item(5)=4 and $Msg0.Item(6)= 0x001 and $Msg0.Item(7)="12 00 32 00" and $Msg0.Item(8)="0xF9 (""Enhanced"")" Then			; Compare the Direction, Channel and Msg ID of the first row
		if $Msg0.Item(0) <>" " and $Msg0.Item(1)="Frame1" and $Msg0.Item(2)="LIN Message" and $Msg0.Item(3)="Tx" and $Msg0.Item(4)=1 and $Msg0.Item(5)=4 and $Msg0.Item(6)= 0x001 and $Msg0.Item(7)="F3 FF FF FF" and $Msg0.Item(8)="0x4A (""Enhanced"")" Then			; Compare the Direction, Channel and Msg ID of the first row
			$FirstMsg=1
			$FirstMsgTime=StringSplit($Msg0.Item(0),":")
			$Tm1=$FirstMsgTime[3]
		Endif
		;if $Msg1.Item(0) <>" " and $Msg1.Item(1)="Frame1" and $Msg1.Item(2)="LIN Message" and $Msg1.Item(3)="Tx" and $Msg1.Item(4)=1 and $Msg1.Item(5)=4 and $Msg1.Item(6)= 0x001 and $Msg1.Item(7)="12 00 32 00" and $Msg1.Item(8)="0xF9 (""Enhanced"")" Then			; Compare the Direction, Channel and Msg ID of the first row
		if $Msg1.Item(0) <>" " and $Msg1.Item(1)="Frame1" and $Msg1.Item(2)="LIN Message" and $Msg1.Item(3)="Tx" and $Msg1.Item(4)=1 and $Msg1.Item(5)=4 and $Msg1.Item(6)= 0x001 and $Msg1.Item(7)="F3 FF FF FF" and $Msg1.Item(8)="0x4A (""Enhanced"")" Then			; Compare the Direction, Channel and Msg ID of the first row

			$SecondMsg=1
			$SecondMsgTime=StringSplit($Msg1.Item(0),":")
			$Tm2=$SecondMsgTime[3]
		Endif
	EndIf

	if ($Tm2-$Tm1)=1 Then
		$TimeDelay=1
	EndIf


	_TxMsgMenuLIN()
	_DelMsgTxWindow(1)																				; Delete Slave and Connect

	_CloseTxWindowArg("LIN")
	sleep(2000)
	Send($linMenu)
	Send("L")
	Send($connectLIN)
	sleep(2000)
	_ConnectDisconnect_LIN()																		; DisConnect
	$rCount=_GetLINMsgWinItemCount()																; count no. of items in msgwindow
	$CountCol=_GetLINMsgWinColCount()																; count no. of columns in msgwindow

	ConsoleWrite("$rCountAfterDeltingSlave = "&$rCount&@CRLF)
	ConsoleWrite("$rCountAfterDeltingSlaveCount1 = "&$CountCol&@CRLF)

	if $rCount >= 2 Then
		$Msg0=_GetMsgWinInfo($LVC_CID_LINMsgWin,0,10)												; Fetch the first row data in the msg window
		if $Msg0.Item(2)= "Event - Sleep" Then
			$Msg0=_GetMsgWinInfo($LVC_CID_LINMsgWin,1,10)
		EndIf
		sleep(2000)
		;if $Msg0.Item(0) <>" " and $Msg0.Item(1)="Frame1" and $Msg0.Item(2)="Error - Slave Not Responding" and $Msg0.Item(4)=1 And $Msg0.Item(6)= 0x001 Then			; Check the error message,Slave is not configured.
		if $Msg0.Item(0) <>" " and $Msg0.Item(1)="Frame1" and $Msg0.Item(2)="Error - Slave Not Responding" and $Msg0.Item(4)=1 And $Msg0.Item(6)= 0x001 Then			; Check the error message,Slave is not configured.
			$ErrMsg=1
		Endif

	EndIf
EndIf

	ConsoleWrite("$FirstMsg = "& $FirstMsg &@CRLF)
	ConsoleWrite("$TimeDelay = "& $TimeDelay &@CRLF)
	ConsoleWrite("$ErrMsg = "& $ErrMsg &@CRLF)

	If($FirstMsg=1 And $TimeDelay=1 And $ErrMsg=1 ) Then
		_WriteResult("Pass","TS_TX_LIN_03")
	Else
		_WriteResult("Fail","TS_TX_LIN_03")
	EndIf


	$isAppNotRes=_CloseApp()																		; Close the app

if $isAppNotRes=1 Then
	_WriteResult("Warning","TS_TX_LIN_03")
EndIf

ConsoleWrite("****End : TS_TX_LIN_03.au3****"&@CRLF)
ConsoleWrite(@CRLF)