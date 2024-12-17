# ATtyni85_Exfiltration

Um projeto para exfiltração de dados usando dispositivos ATtiny85, configurados para simular HID (Human Interface Device) e transferir dados de forma discreta.

---

## 📋 Funcionalidades

*Extrai as credenciais: O PowerShell obtém as credenciais inseridas e armazena os dados de nome de usuário e senha nas variáveis $user e $pass.

*Envia os dados para o webhook: O script utiliza Invoke-WebRequest para enviar os dados via HTTP POST para o webhook especificado (substitua o URL com o seu próprio webhook).

*Finaliza e faz a limpeza: O script finaliza a execução e realiza a limpeza de arquivos temporários, além de acender um LED como um sinal de término do processo.

## 🚀 Configuração
### 1. Requisitos
- ATtiny85 - Digispark).
- Software para upload do script (Arduino IDE).
