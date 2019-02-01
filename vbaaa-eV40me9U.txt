Private Sub Command65_Click()
'Update changes to from temp_helicopter_engine to helicopter_engine

'dump components to temp table so we can update component quantities
'Clear the temp_helicopter_component table
DoCmd.SetWarnings warningsoff
DoCmd.RunSQL "DELETE temp_helicopter_component.* FROM temp_helicopter_component;"
DoCmd.SetWarnings warningson

'setup recordset to temp table
Dim myRthc As Recordset
Set myRthc = CurrentDb.OpenRecordset("temp_helicopter_component", dbOpenDynaset, dbSeeChanges)

'Loop the subform and populate the temp table from it
If Forms!heli_MAIN!heli_components_list.Form.Recordset.BOF = False Then Forms!heli_MAIN!heli_components_list.Form.Recordset.MoveFirst
While Forms!heli_MAIN!heli_components_list.Form.Recordset.EOF = False
  myRthc.AddNew
  myRthc![helicopter_component_id] = Forms!heli_MAIN!heli_components_list.Form.helicopter_component_id
  myRthc![helicopter_id] = Forms!heli_MAIN!heli_components_list.Form.helicopter_id
  myRthc![part_no] = Forms!heli_MAIN!heli_components_list.Form.part_no
  myRthc![hmc] = Forms!heli_MAIN!heli_components_list.Form.hmc
  myRthc![display_order] = Forms!heli_MAIN!heli_components_list.Form.display_order
  myRthc![quantity] = Forms!heli_MAIN!heli_components_list.Form.quantity
  myRthc![comp_name] = Forms!heli_MAIN!heli_components_list.Form.comp_name
  myRthc.Update
   
  Forms!heli_MAIN!heli_components_list.Form.Recordset.MoveNext
Wend

'setup recordset to helicopter_engine table
Dim myRhe As Recordset
Set myRhe = CurrentDb.OpenRecordset("helicopter_engine", dbOpenDynaset, dbSeeChanges)
Dim myHid As Integer
Dim myEid As Integer

'Loop heli_engine_edit form and update helicopter_engine table from it
If Forms!heli_engine_edit.Recordset.BOF = False Then Forms!heli_engine_edit.Recordset.MoveFirst
While Forms!heli_engine_edit.Recordset.EOF = False
  myRhe.FindFirst "[helicopter_engine_id] = " & Forms!heli_engine_edit.helicopter_engine_id
  myRhe.Edit
  myRhe![engine_quantity] = Forms!heli_engine_edit.engine_quantity
  myRhe![primary_engine] = Forms!heli_engine_edit.primary_engine
  myRhe![entered_date] = Forms!heli_engine_edit.entered_date
  myRhe![entered_user] = Forms!heli_engine_edit.entered_user
  myRhe.Update
  myHid = Forms!heli_engine_edit.helicopter_id
  myEid = Forms!heli_engine_edit.engine_id
  'update the qty in the temp_helicopter_components table for all the same engine id for this helicopter id
  If myRthc.BOF = False Then myRthc.MoveFirst
  Do Until myRthc.EOF
    If myRthc![helicopter_id] = myHid Then
      myRthc.Edit
      myRthc![quantity] = Forms!heli_engine_edit.engine_quantity
      myRthc.Update
    End If
    myRthc.MoveNext
  Loop
  Forms!heli_engine_edit.Recordset.MoveNext
Wend

'setup recordset to helicopter_component table
Dim myRhc As Recordset
Set myRhc = CurrentDb.OpenRecordset("helicopter_component", dbOpenDynaset, dbSeeChanges)

'Loop temp_helicopter_components and update helicopter_components
If myRthc.BOF = False Then myRthc.MoveFirst
Do Until myRthc.EOF
  myRhc.FindFirst "[helicopter_component_id] =" & myRthc![helicopter_component_id]
  myRhc.Edit
  myRhc![quantity] = myRthc![quantity]
  myRhc.Update
  myRthc.MoveNext
Loop

'requery form
Forms!heli_MAIN!heli_engine.Form.Requery
Forms!heli_MAIN!heli_components_list.Requery


'Calculate HMC

If Forms!heli_MAIN!heli_components_list.Form.Recordset.RecordCount < 1 Then Exit Sub


'setup recordset to helicopter_component & helicopter to update hmc calcs

Dim myHMC As Single


'zero out the hmc totals in the engine table before adding to them
Do Until myRhe.EOF
  If myRhe![helicopter_id] = Forms!heli_MAIN!heli_components_list.Form.helicopter_id Then
    myRhe.Edit
    myRhe![hmc_total] = 0
    myRhe.Update
  End If
  myRhe.MoveNext
Loop

'Loop through heli_components_list subform to calc each line
If Forms!heli_MAIN!heli_components_list.Form.Recordset.BOF = False Then Forms!heli_MAIN!heli_components_list.Form.Recordset.MoveFirst
While Forms!heli_MAIN!heli_components_list.Form.Recordset.EOF = False
  If Forms!heli_MAIN!heli_components_list.Form.oh_rt = "OH" Then
    If IsError(Eval(DLookup("[oh_hmc]", "formulas"))) Then
      myHMC = 0
    Else
      myHMC = Eval(DLookup("[oh_hmc]", "formulas"))
    End If
  ElseIf Forms!heli_MAIN!heli_components_list.Form.oh_rt = "RT" Then
    If IsError(Eval(DLookup("[rt_hmc]", "formulas"))) Then
      myHMC = 0
    Else
      myHMC = Eval(DLookup("[rt_hmc]", "formulas"))
    End If
  End If

  'Turn the value to 0 if calculate HMC is unchecked
  If Forms!heli_MAIN!heli_components_list.Form.hmc_calc = False Then
    myHMC = 0
  End If
  
  ' Acumulate totals for each engine
  If IsNull(Forms!heli_MAIN!heli_components_list.Form.engine_id) Then
    myRhe.MoveFirst
    Do Until myRhe.EOF
      If myRhe![helicopter_id] = Forms!heli_MAIN!heli_components_list.Form.helicopter_id Then
        myRhe.Edit
        myRhe![hmc_total] = myRhe![hmc_total] + myHMC
        myRhe.Update
      End If
      myRhe.MoveNext
    Loop
  Else
    myRhe.MoveFirst
    Do Until myRhe.EOF
      If myRhe![helicopter_id] = Forms!heli_MAIN!heli_components_list.Form.helicopter_id Then
        If myRhe![engine_id] = Forms!heli_MAIN!heli_components_list.Form.engine_id Then
          myRhe.Edit
          myRhe![hmc_total] = myRhe![hmc_total] + myHMC
          myRhe.Update
        End If
      End If
      myRhe.MoveNext
    Loop
  End If
    
  ' Update HMC in helicopter_component table
  myRhc.FindFirst "[helicopter_component_id] = " & Forms!heli_MAIN!heli_components_list.Form.helicopter_component_id
  myRhc.Edit
  myRhc![hmc] = myHMC
  myRhc.Update
        
  ' Move next record
  Forms!heli_MAIN!heli_components_list.Form.Recordset.MoveNext
Wend



' Requery sub form
Forms!heli_MAIN!heli_components_list.Form.Requery
Forms!heli_MAIN!heli_engine.Form.Requery



' Calculate HMC Range (HMC Form) as long as sch/unsch is not blank
'Get the HMC total for the primary engine for OH_RET

' Exit if a record does not exist in the HMC form
Dim myR As Recordset
Set myR = CurrentDb.OpenRecordset("hourly_maintenance_cost", dbOpenDynaset, dbSeeChanges)
myR.FindFirst "helicopter_id = " & Forms!heli_MAIN.helicopter_id
If myR.NoMatch Then
  Exit Sub
  myR.Close
  myRhc.Close
  myRhe.Close
  myRthc.Close
  Set myR = Nothing
  Set myRhc = Nothing
  Set myRhe = Nothing
  Set myRthc = Nothing
End If


' Exit if sch/unsch is blank
If Not IsNull(Forms!heli_MAIN!hourly_maintenance_cost.Form.sch_unsch) Then
  If myRhe.BOF = False Then myRhe.MoveFirst
  Do Until myRhe.EOF
    If myRhe![helicopter_id] = Forms!heli_MAIN.helicopter_id Then
      If myRhe![primary_engine] = True Then
        Forms!heli_MAIN!hourly_maintenance_cost.Form.oh_ret = Round(myRhe![hmc_total], 2)
      End If
    End If
    myRhe.MoveNext
  Loop
  If IsNull(Forms!heli_MAIN!hourly_maintenance_cost.Form.oh_ret) Then
    MsgBox "Make sure 1 engine is selected as primary and HMC is calculated in the Eng-Comps Tab"
  End If

  ' Get Labor Rate
  Forms!heli_MAIN!hourly_maintenance_cost.Form.labor = DLookup("[labor_rate]", "labor_rate")

  'calculate HMC range as long as sched_unsch is not blank
  Forms!heli_MAIN!hourly_maintenance_cost.Form.range_low = (Forms!heli_MAIN!hourly_maintenance_cost.Form.sch_unsch * Forms!heli_MAIN!hourly_maintenance_cost.Form.labor) + Forms!heli_MAIN!hourly_maintenance_cost.Form.oh_ret
  Forms!heli_MAIN!hourly_maintenance_cost.Form.range_high = ((Forms!heli_MAIN!hourly_maintenance_cost.Form.sch_unsch * 1.5) * Forms!heli_MAIN!hourly_maintenance_cost.Form.labor) + Forms!heli_MAIN!hourly_maintenance_cost.Form.oh_ret
  Forms!heli_MAIN!hourly_maintenance_cost.Form.Refresh
Else
  MsgBox "You must add a value to Sch/Unsch Before Calculating HMC range"
End If


'Free Up Memory
myR.Close
myRhe.Close
myRthc.Close
myRhc.Close
Set myR = Nothing
Set myRhe = Nothing
Set myRthc = Nothing
Set myRhc = Nothing

'close form
DoCmd.Close


End Sub