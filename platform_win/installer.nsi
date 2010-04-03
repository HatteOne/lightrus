Name "Adobe Photoshop Lightroom Rus"

OutFile "lightroom_rus_261.exe"
RequestExecutionLevel admin
SilentInstall silent
SetCompressor /FINAL lzma
Icon ..\res\images\app.ico

Page instfiles

Section ""

	; Получаем уникальное имя папки
	GetTempFileName $0 $TEMP
	Delete $0
	CreateDirectory $0
	SetOutPath $0
	
	; Копируем во временную директорию файлы для программы
	File release\lightroom_rus_261.exe
	File release\*.dll
	
	ExecWait $0\lightroom_rus_261.exe
	
	SetOutPath $TEMP
	RMDir /r $0
	
SectionEnd
