const express = require('express');
const path = require('path');
const fs = require('fs');

const app = express();
const PORT = 3000;

// Serve index.html at root
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

// Serve the EXE file manually (it's outside the website folder)
app.get('/logica-installer.exe', (req, res) => {
  const filePath = path.join(__dirname, '..', 'logica-installer.exe');

  if (fs.existsSync(filePath)) {
    res.download(filePath, 'logica-installer.exe', err => {
      if (err) {
        console.error('Download error:', err);
        res.status(500).send('Error downloading file.');
      }
    });
  } else {
    console.error('Installer not found at', filePath);
    res.status(404).send('Installer not found.');
  }
});

const filePath = path.join(__dirname, '..', 'logica-installer.exe');
console.log("Installer Exists:", fs.existsSync(filePath))

// Start server
app.listen(PORT, () => {
  console.log(`Server running at http://localhost:${PORT}`);
});
