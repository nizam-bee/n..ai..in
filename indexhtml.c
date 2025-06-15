# ✅ Full Project: `n.ai.in` — Smarter Search Engine (Frontend + Backend with Login)

This complete project is structured with React (Vite) for frontend, Express.js for backend, and Firebase Authentication for login. You can paste this into GitHub and deploy on Vercel (frontend) and Render (backend).

---

### 📁 Folder Structure
```
n-ai-in/
├── client/               # React frontend
│   ├── public/
│   ├── src/
│   │   ├── App.jsx
│   │   ├── Home.jsx
│   │   ├── Results.jsx
│   │   ├── Login.jsx
│   │   ├── main.jsx
│   │   └── styles.css
│   ├── index.html
│   ├── package.json
│   └── vite.config.js
├── server/               # Node backend
│   ├── index.js
│   └── package.json
└── firebaseConfig.js     # Firebase credentials
```

---

## ✅ `client/index.html`
```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <link rel="icon" href="🇮🇳" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>n.ai.in</title>
  </head>
  <body>
    <div id="root"></div>
    <script type="module" src="/src/main.jsx"></script>
  </body>
</html>
```

---

## ✅ `client/src/main.jsx`
```jsx
import React from 'react';
import ReactDOM from 'react-dom/client';
import App from './App';
import { BrowserRouter } from 'react-router-dom';

ReactDOM.createRoot(document.getElementById('root')).render(
  <BrowserRouter>
    <App />
  </BrowserRouter>
);
```

---

## ✅ `client/src/App.jsx`
```jsx
import React from 'react';
import { Routes, Route } from 'react-router-dom';
import Home from './Home';
import Results from './Results';
import Login from './Login';
import './styles.css';

export default function App() {
  return (
    <Routes>
      <Route path="/" element={<Home />} />
      <Route path="/search" element={<Results />} />
      <Route path="/login" element={<Login />} />
    </Routes>
  );
}
```

---

## ✅ `client/src/Home.jsx`
```jsx
import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom';

export default function Home() {
  const [query, setQuery] = useState('');
  const navigate = useNavigate();

  const handleSearch = (e) => {
    e.preventDefault();
    if (query.trim()) navigate(`/search?q=${encodeURIComponent(query)}`);
  };

  return (
    <div className="home">
      <h1 className="logo">🇮🇳 n.ai.in</h1>
      <form onSubmit={handleSearch}>
        <input
          type="text"
          placeholder="Search smarter than Google..."
          value={query}
          onChange={(e) => setQuery(e.target.value)}
          className="search-bar"
        />
        <button type="submit" className="search-btn">Search</button>
      </form>
      <a href="/login">Login</a>
    </div>
  );
}
```

---

## ✅ `client/src/Results.jsx`
```jsx
import React from 'react';
import { useLocation, useNavigate } from 'react-router-dom';

function useQuery() {
  return new URLSearchParams(useLocation().search);
}

export default function Results() {
  const q = useQuery().get('q');
  const navigate = useNavigate();

  const dummyResults = [
    {
      title: `n.ai.in – The Smarter Search`,
      link: `https://n.ai.in`,
      snippet: `Smarter than Google. Get results, code, news in 0.4s.`,
    },
    {
      title: `You searched for "${q}"`,
      link: `https://example.com?q=${q}`,
      snippet: `Example results for your query.`
    },
  ];

  return (
    <div className="results">
      <div className="top-bar">
        <span className="logo-small" onClick={() => navigate('/')}>🇮🇳 n.ai.in</span>
        <input defaultValue={q} className="search-input" />
      </div>
      <p className="meta">About {Math.floor(Math.random() * 10000)} results (0.4 seconds)</p>
      {dummyResults.map((r, i) => (
        <div key={i} className="result-card">
          <a href={r.link} target="_blank" className="title">{r.title}</a>
          <div className="link">{r.link}</div>
          <p className="desc">{r.snippet}</p>
        </div>
      ))}
    </div>
  );
}
```

---

## ✅ `client/src/Login.jsx`
```jsx
import React, { useState } from 'react';
import { getAuth, signInWithEmailAndPassword } from 'firebase/auth';
import { initializeApp } from 'firebase/app';
import firebaseConfig from '../firebaseConfig';

initializeApp(firebaseConfig);

export default function Login() {
  const [email, setEmail] = useState('');
  const [password, setPassword] = useState('');

  const handleLogin = async () => {
    try {
      const auth = getAuth();
      await signInWithEmailAndPassword(auth, email, password);
      alert("Logged in!");
    } catch (err) {
      alert("Login failed");
    }
  };

  return (
    <div className="home">
      <h2>Login to n.ai.in</h2>
      <input value={email} onChange={e => setEmail(e.target.value)} placeholder="Email" />
      <input value={password} type="password" onChange={e => setPassword(e.target.value)} placeholder="Password" />
      <button onClick={handleLogin}>Login</button>
    </div>
  );
}
```

---

## ✅ `client/src/styles.css`
```css
body {
  font-family: Arial;
  background: #f4f4f4;
  margin: 0;
  padding: 0;
}
.home {
  text-align: center;
  margin-top: 80px;
}
.search-bar {
  width: 60%;
  padding: 12px;
  font-size: 18px;
}
.search-btn {
  padding: 12px 20px;
  font-size: 18px;
  background: #2e86de;
  color: white;
  border: none;
  margin-left: 10px;
  cursor: pointer;
}
.results {
  padding: 20px;
}
.result-card {
  background: white;
  margin: 10px;
  padding: 15px;
  border-radius: 8px;
}
.logo {
  font-size: 3rem;
}
```

---

## ✅ `firebaseConfig.js`
```js
export default {
  apiKey: "<your-key>",
  authDomain: "<your-domain>",
  projectId: "<your-project-id>",
  storageBucket: "<your-bucket>",
  messagingSenderId: "<your-msg-id>",
  appId: "<your-app-id>"
};
```

---

## ✅ `server/index.js`
```js
import express from 'express';
import cors from 'cors';

const app = express();
app.use(cors());

app.get("/api/search", (req, res) => {
  const q = req.query.q;
  res.json({
    message: `You searched for ${q}`,
    results: [
      { title: "Result 1", link: "https://example.com/1" },
      { title: "Result 2", link: "https://example.com/2" },
    ],
  });
});

app.listen(3001, () => console.log("API running on http://localhost:3001"));
```

---

## ✅ `server/package.json`
```json
{
  "name": "n-ai-in-api",
  "version": "1.0.0",
  "type": "module",
  "main": "index.js",
  "dependencies": {
    "express": "^4.18.2",
    "cors": "^2.8.5"
  }
}
```

---

Let me know if you want me to ZIP this whole project so you can upload it instantly.
