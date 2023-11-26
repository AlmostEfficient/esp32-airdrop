// web_content.h
#ifndef WEB_CONTENT_H
#define WEB_CONTENT_H

const char* html_content = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Money printer 🖨</title>
  <style>
    body { 
      background-color: black;
      color: white;
      font-family: Arial, 
      sans-serif; 
      margin: 0; 
      padding: 0; 
    }
    .container { padding: 20px; }
    h1 { color: #0f6ecd; }
    #code { margin-top: 20px; color: green; }
    .button { margin-top: 10px; padding: 10px; background-color: #0f6ecd; color: white; border: none; cursor: pointer; }
    button:disabled,
    button[disabled]{
      border: 1px solid #999999;
      background-color: #cccccc;
      color: #666666;
    }
    .svg-container{
      width: 200px;
    }
  </style>
</head>
<body>
  <div class="container">
    <h1>WASSUP HOMIES!</h1>
    <p>THIS SERVER IS RUNNING ON A TINY BOARD. 💸</p>
    <p>The claim button will be ready at 5 minutes!</p>
    
    <div id="code"></div>
        
    <button class="button" id="registerButton" style="display: block;">Register</button>
    <button class="button" id="claimButton" disabled style="display: block;">Claim Code</button>
    <button class="button" id="api-req" >Make API request test</button>
    <button class="button" id="ip" >Input IP</button>
    <button class="button" id="test-connection" onclick="testConnection()">Test Connection</button>


    <div id="timer" style="display: none;">Connected for: 00:00:00</div>

    <div class="container">
      Powered by
      <div class="svg-container">
        <svg viewBox="0 0 646 96" fill="none" xmlns="http://www.w3.org/2000/svg">
          <g clip-path="url(#a)">
            <path d="m108.53 75.69-17.72 19a4.099 4.099 0 0 1-3 1.31h-84a2.06 2.06 0 0 1-1.51-3.46l17.7-19a4.102 4.102 0 0 1 3-1.31h84a2.05 2.05 0 0 1 1.53 3.46ZM90.81 37.42a4.14 4.14 0 0 0-3-1.31h-84a2.06 2.06 0 0 0-1.51 3.46L20 58.58a4.14 4.14 0 0 0 3 1.31h84a2.06 2.06 0 0 0 1.5-3.46L90.81 37.42Zm-87-13.65h84a4.098 4.098 0 0 0 3-1.31l17.72-19a2.052 2.052 0 0 0-.387-3.14A2.05 2.05 0 0 0 107 0H23a4.1 4.1 0 0 0-3 1.31l-17.7 19a2.06 2.06 0 0 0 1.51 3.46Z" fill="url(#b)"/>
            <path d="M210.94 40.6H166V25.8h56.62V11h-56.77A14.768 14.768 0 0 0 151 25.69v15a14.768 14.768 0 0 0 14.85 14.71h45v14.8h-58.78V85h58.87a14.766 14.766 0 0 0 13.695-9.044 14.76 14.76 0 0 0 1.155-5.646v-15a14.769 14.769 0 0 0-14.85-14.71ZM298 11h-45.11a14.773 14.773 0 0 0-13.731 9.035A14.752 14.752 0 0 0 238 25.69v44.62c.01 1.943.404 3.865 1.159 5.656A14.77 14.77 0 0 0 252.89 85H298a14.768 14.768 0 0 0 14.85-14.69V25.69a14.76 14.76 0 0 0-4.383-10.42A14.76 14.76 0 0 0 298 11Zm-.11 59.2H253V25.8h44.87l.02 44.4ZM456 11h-44a14.768 14.768 0 0 0-14.85 14.69V85h15V60.69h43.8V85h15V25.69A14.766 14.766 0 0 0 456 11Zm-.11 34.89h-43.8V25.8h43.8v20.09ZM631.15 11h-44a14.768 14.768 0 0 0-14.85 14.69V85h15V60.69H631V85h15V25.69a14.76 14.76 0 0 0-4.383-10.42A14.771 14.771 0 0 0 631.15 11ZM631 45.89h-43.8V25.8H631v20.09ZM544 70.2h-6l-21.45-53a9.887 9.887 0 0 0-9.16-6.2h-13.31a9.845 9.845 0 0 0-9.131 6.035 9.86 9.86 0 0 0-.769 3.765V85h15V25.8h6l21.44 53a9.915 9.915 0 0 0 9.2 6.16h13.31a9.843 9.843 0 0 0 6.98-2.85 9.853 9.853 0 0 0 2.92-6.95V11H544v59.2ZM341.1 11h-15v59.31a14.763 14.763 0 0 0 4.4 10.438A14.775 14.775 0 0 0 341 85h45V70.2h-44.9V11Z" fill="#fff"/>
          </g>
          <defs>
            <linearGradient id="b" x1="10.81" y1="98.29" x2="98.89" y2="-1.01" gradientUnits="userSpaceOnUse">
              <stop offset=".08" stop-color="#9945FF"/>
              <stop offset=".3" stop-color="#8752F3"/>
              <stop offset=".5" stop-color="#5497D5"/>
              <stop offset=".6" stop-color="#43B4CA"/>
              <stop offset=".72" stop-color="#28E0B9"/>
              <stop offset=".97" stop-color="#19FB9B"/>
            </linearGradient>
            <clipPath id="a">
              <path fill="#fff" d="M0 0h646v96H0z"/>
            </clipPath>
          </defs>
        </svg>
      </div>
    </div>
  </div>
  <script>
    const serverIP = '';
    
    document.getElementById('api-req').addEventListener('click', function() {
      fetch(`http://${serverIP}/register_device?uid=1234`).then(response => response.json()).then(data => {
        alert('API request worked! ' + data.name);
      });
    });


    document.getElementById('ip').addEventListener('click', function() {
      const ip = prompt('Enter IP address of server', serverIP);
      if (ip) {
        alert('IP address set to: ' + ip);
        serverIP = ip;
      }
    });

    async function testConnection() {
      const url = `http://${serverIP}/ping`;
      try {
        const response = await fetch(url, { method: 'GET' });
        if (response.ok) {
          alert('Connection successful!');
        }
      } catch (error) {
        alert(`No response from ${serverIP}`);
      }
    }

    let connectionTimer;
    let connectedTime = 0;
    let userId = getOrGenerateUserId();

    document.addEventListener('DOMContentLoaded', function() {
      if (userId && getCookie('registered')) {
        startConnectionTimer();
        showClaimButton();
      } else {
        showRegisterButton();
      }
    });
    
    function showRegisterButton() {
      document.getElementById('registerButton').style.display = 'block';
      document.getElementById('registerButton').addEventListener('click', function() {
        registerDevice(userId);
      });
    }

    function showClaimButton() {
      const claimButton = document.getElementById('claimButton');
      claimButton.style.display = 'block';
      claimButton.addEventListener('click', function() {
        claimCode(userId);
      });
      checkClaimAvailability();
    }

    function checkClaimAvailability(userId) {
      setInterval(() => {
        if (connectedTime >= 5) { // 5 minutes in seconds
          document.getElementById('claimButton').disabled = false;
        }
      }, 1000); // Check every second
    }

    function claimCode(userId) {
      fetch(`/claim_code?uid=${userId}`)
        .then(response => response.text())
        .then(code => {
          if (response.ok) {
            navigator.clipboard.writeText(code).then(() => {
              alert('Code copied to clipboard: ' + code);
              document.getElementById('claimButton').disabled = true;
            });
          } else {
            alert('Error: ' + code);
          }
        });
    }

    function getOrGenerateUserId() {
      let userId = getCookie('userId');
      if (!userId) {
        userId = generateUniqueId();
        setCookie('userId', userId, 1); // Store for 1 day
      }
      return userId;
    }

    function generateUniqueId() {
      return crypto.randomUUID();
    }

    function setCookie(name, value, days) {
      let expires = "";
      if (days) {
        let date = new Date();
        date.setTime(date.getTime() + (days * 24 * 60 * 60 * 1000));
        expires = "; expires=" + date.toUTCString();
      }
      document.cookie = name + "=" + (value || "")  + expires + "; path=/";
    }

    function getCookie(name) {
      let nameEQ = name + "=";
      let ca = document.cookie.split(';');
      for(let i=0; i < ca.length; i++) {
        let c = ca[i];
        while (c.charAt(0)==' ') c = c.substring(1,c.length);
        if (c.indexOf(nameEQ) == 0) return c.substring(nameEQ.length,c.length);
      }
      return null;
    }

    function registerDevice(userId) {
      fetch(`/register_device?uid=${userId}`).then(response => {
        if (response.ok) {
          setCookie('registered', 'true', 1); // Store registration state for 1 day
          showClaimButton();
          startConnectionTimer();
          document.getElementById('registerButton').style.display = 'none';
          console.log("Device registered.");
        }
        else {
          alert('Error: Server is having trouble :(');
        }
      });
    }

    function startConnectionTimer() {
      document.getElementById('timer').style.display = 'block';
      connectionTimer = setInterval(() => {
        connectedTime++;
        updateTimerDisplay();
      }, 1000); // Update every second
    }

    function updateTimerDisplay() {
      let hours = Math.floor(connectedTime / 3600);
      let minutes = Math.floor((connectedTime % 3600) / 60);
      let seconds = connectedTime % 60;
      let formattedTime = [hours, minutes, seconds].map(unit => String(unit).padStart(2, '0')).join(':');
      document.getElementById('timer').innerText = 'Connected for: ' + formattedTime;
    }
  </script>
</body>
</html>
)rawliteral";

#endif // WEB_CONTENT_H
