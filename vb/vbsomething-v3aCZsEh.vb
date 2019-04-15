Dim Output
Dim SUFFIXA
Dim Printed
Dim Final

If [PANEL] = "NSFH" Then
   Printed = "NSFHA"
ElseIF [PANEL] = "NA" Then
   Printed = "NA"
ElseIf [PANEL_TYP] = "NA" Then
   Printed = "Yes"
ElseIf RIGHT([PANEL_TYP],11) = "NOT PRINTED" Then
   Printed = "No"
ElseIf [PANEL_TYP] = "NP" Then
   Printed = "No"
Else
   Printed = "Yes"
End If

Dim sfx
sfx = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

Dim idx
idx = sfx.IndexOf([SUFFIX])

If idx < 0 Then 
   idx = -999
Else
   idx = idx + 1
EndIf

If Printed = "NSFHA" Then
   Final = 200 + idx
ElseIf Printed = "No" Then
   Final = 100 + idx
ELse
   Final = idx
End If

If [MINOR5] = -999 Then
   Final = -999
End If

Output = Final