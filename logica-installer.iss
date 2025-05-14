[Setup]
AppName=Logica
AppVersion=1.0.0
DefaultDirName={pf}\Logica
DefaultGroupName=Logica
OutputDir=.
OutputBaseFilename=logica-installer
Compression=lzma
SolidCompression=yes

[Files]
Source: "build\Release\logica.exe"; DestDir: "{app}"; Flags: ignoreversion
Source: "README.txt"; DestDir: "{app}"; Flags: ignoreversion
Source: "LICENSE"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\Logica"; Filename: "{app}\logica.exe"
Name: "{commondesktop}\Logica"; Filename: "{app}\logica.exe"; Tasks: desktopicon

[Tasks]
Name: "desktopicon"; Description: "Create a &desktop icon"; GroupDescription: "Additional icons:"

[Run]
Filename: "{cmd}"; Parameters: "/C setx PATH ""{app};%PATH%"""; Flags: runhidden
