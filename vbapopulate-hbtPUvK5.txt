Private Sub PopulateTable()
'
'   This subroutine populates a temp table with component data.
'
'   The following is the core pseudocode for what this subroutine does.
'   ***1***     Truncate @temp_eng_comp_list
'   ***2***     Generate recordsets based on <RunQuery> and @temp_eng_comp_list
'   ***3***     Loop through all records from <RunQuery>
'   ***3.a***   Generate recordset from @engine_components where matching [part_no] are found
'   ***3.b***   If no records from @engine_components, add new record to @temp_eng_comp_list with a Null-filled engine_id field
'   ***3.c***   If records from @engine_components, loop through recordset and add new records for each item.
'
'   ***1***

RunQuery ("DELETE FROM temp_eng_comp_list")

'   ***2***
Dim sql As String
sql = GetSelect & GetWhere & GetOrder

Dim ins As Recordset
Set ins = CurrentDb.OpenRecordset("temp_eng_comp_list", dbOpenDynaset, dbSeeChanges)

Dim rs As Recordset
Set rs = CurrentDb.OpenRecordset(sql, dbOpenDynaset, dbSeeChanges)

Dim mid As Recordset

'   ***3***
If Not rs.BOF Then rs.MoveFirst
While Not rs.EOF
    
    '   ***3.a***
    sql = "SELECT engine_id FROM engine_components WHERE engine_components.part_no=""" & rs![part_no] & """"
    Set mid = CurrentDb.OpenRecordset(sql, dbOpenDynaset, dbSeeChanges)
    
    If mid.BOF And mid.EOF Then
    
    '   ***3.b***
        ins.AddNew
            
        ins![category] = rs![category]
        ins![component_id] = rs![component_id]
        ins![part_no] = rs![part_no]
        ins![comp_name] = rs![comp_name]
        ins![engine_id] = Null
        
        ins.Update
        
    Else
    
        '   ***3.c***
        If Not mid.BOF Then mid.MoveFirst
        While Not mid.EOF
        
            ins.AddNew
            
            ins![category] = rs![category]
            ins![component_id] = rs![component_id]
            ins![part_no] = rs![part_no]
            ins![comp_name] = rs![comp_name]
            ins![engine_id] = mid![engine_id]
            
            ins.Update
            
            mid.MoveNext
            
        Wend
    
    End If
    
    rs.MoveNext
    
Wend

End Sub