Private Sub Command65_Click()
'	Clear @temp_helicopter_component table
Dim sql As String
sql = "DELETE FROM temp_helicopter_component"
DBO.Query (sql)

'	Update @helicopter_engine and @helicopter_component data based on current form data
Dim rs2 As Recordset
With Forms!heli_engine_edit.Recordset
	If Not .BOF Then .MoveFirst
	While Not .EOF
	
		sql = "UPDATE helicopter_engine SET engine_quantity=" & ![engine_quantity] & ", primary_engine=" & ![primary_engine] & ", entered_date=#" & ![entered_date] & "#, entered_user=" & ![entered_user] & "WHERE helicopter_engine_id=" & ![helicopter_engine_id]
		DBO.Query (sql)
		
		sql = "SELECT quantity FROM helicopter_component WHERE part_no IN (SELECT part_no FROM engine_components WHERE engine_id=" & ![engine_id]
		Set rs2 = DBO.Edit (sql)
		
		If Not rs2.BOF Then rs2.MoveFirst
		While Not rs2.EOF 
			rs2.Edit
			rs2![quantity] = ![engine_quantity]
			rs2.Update
			rs2.MoveNext
		Wend
	Wend
End With
'requery form
Forms!heli_MAIN!heli_engine.Form.Requery
Forms!heli_MAIN!heli_components_list.Requery

Call helper_functions_jimp1.CalcHMC_Adjusted

'close form
DoCmd.Close
End Sub