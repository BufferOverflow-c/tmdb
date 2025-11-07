# TMDB CLI Tool

Use the TMDB (The Movie Database) API to fetch and display movie information directly in your terminal.

https://roadmap.sh/projects/tmdb-cli
---

## Overview

In this project, you will build a simple command-line interface (CLI) application to fetch data from the TMDB API and display it in the terminal.
This project helps you practice working with public APIs, handling JSON data, and building robust CLI tools.

---

## Features

- Fetch and display:
  - 🎬 **Now Playing** movies
  - ⭐ **Popular** movies
  - 🏆 **Top Rated** movies
  - 🎟️ **Upcoming** movies
- Display movie titles and key details (release date, rating, overview, etc.)
- Gracefully handle API and network errors
- Simple and user-friendly CLI commands

---

## Example Usage

```bash
# Show now playing movies
tmdb-app --type "playing"

# Show popular movies
tmdb-app --type "popular"

# Show top rated movies
tmdb-app --type "top"

# Show upcoming movies
tmdb-app --type "upcoming"
