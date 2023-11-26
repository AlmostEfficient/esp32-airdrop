// web_content.h
#ifndef WEB_CONTENT_H
#define WEB_CONTENT_H

const char* html_content = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ESP32 Landing Page</title>
  <style>
    body { font-family: Arial, sans-serif; margin: 0; padding: 0; }
    .container { padding: 20px; }
    h1 { color: #0f6ecd; }
  </style>
</head>
<body>
  <div class="container">
    
    <h1>WASSUP HOMIES!</h1>
    <p>THIS SERVER IS RUNNING ON A TINY BOARD. 💸</p>
  </div>
  <script>
    // Your JavaScript code here
  </script>
</body>
</html>
)rawliteral";

#endif // WEB_CONTENT_H
