.set noreorder


; .global fx_rethookPercent
; .ent fx_rethookPercent
; fx_rethookPercent:
; lw $v0, hookAdd0
; jr $ra
; nop
; hookAdd0:
; addiu $v0, $zero, 50
; .end fx_rethookPercent

.global fx_rethookIsLowBattery
.ent fx_rethookIsLowBattery
fx_rethookIsLowBattery:
lw $v0, hookAdd1
jr $ra
nop
hookAdd1:
addiu $v0, $zero, 50
.end fx_rethookIsLowBattery

; .global fx_rethookIsBatteryExist
; .ent fx_rethookIsBatteryExist
; fx_rethookIsBatteryExist:
; lw $v0, hookAdd2
; jr $ra
; nop
; hookAdd2:
; addiu $v0, $zero, 0x0001
; .end fx_rethookIsBatteryExist
