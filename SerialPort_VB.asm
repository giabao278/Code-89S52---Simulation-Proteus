ORG		0000H
LJMP	SETUP
ORG		0030H

SETUP:
	MOV		SCON,#50H	
	MOV		A,PCON		
	SETB	ACC.7		
	MOV		PCON,A		
	MOV		TMOD,#20H 	
	MOV		TH1,#-13
	SETB	TR1			
LOOP:
	ACALL	RECEIVE_DATA
	MOV		R7,A
	ACALL	ON_LED
	SJMP 	LOOP
	
ON_LED:
	CJNE	R7,#31H,LB1
	CPL		P1.0
	RET
	LB1:
	CJNE	R7,#32H,LB2
	CPL		P1.1
	RET
	LB2:
	CJNE	R7,#33H,LB3
	CPL		P1.2
	RET
	LB3:
	CJNE	R7,#34H,LB4
	CPL		P1.3
	RET
	LB4:
	CJNE	R7,#35H,LB5
	CPL		P1.4
	RET
	LB5:
	CJNE	R7,#36H,LB6
	CPL		P1.5
	RET
	LB6:
	CJNE	R7,#37H,LB7
	CPL		P1.6
	RET
	LB7:
	CJNE	R7,#38H,LB8
	CPL		P1.7
	RET
	LB8:
	CJNE	R7,#30H,LB9
	MOV		P1,#0FFH
	RET
	LB9:
	CJNE	R7,#39H,DONE
	MOV		P1,#00H
	DONE:
	RET
	
RECEIVE_DATA:		
	JNB		RI,$			
	CLR		RI
	MOV		A,SBUF
	RET

END