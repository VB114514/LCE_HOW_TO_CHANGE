@echo off
title Git One-Click Commit to test branch

set "project_path=%~dp0"
set "repo_url=https://github.com/VB114514/LCE_HOW_TO_CHANGE"
set "branch_name=S_26W04A"

echo ========================================
echo   Git One-Click Commit to %branch_name%
echo ========================================
echo Project: %project_path%
echo Branch: %branch_name%
echo.

cd /d "%project_path%"

:: Init if needed
if not exist ".git" (
    echo Initializing git repo...
    git init
    git remote add origin %repo_url%
    echo.
)

git remote set-url origin %repo_url% 2>nul

:: Show current branch and status
echo Current status:
git status
echo.

:: Switch to test branch (create if not exists)
echo Switching to %branch_name% branch...
git checkout %branch_name% 2>nul
if errorlevel 1 (
    echo Branch %branch_name% not found, creating...
    git checkout -b %branch_name%
)
echo.

:: Add all changes
echo Adding files...
git add .
if errorlevel 1 (
    echo Add failed!
    pause
    exit /b
)

:: Commit
set /p commit_msg="Commit message (Enter for auto): "
if "%commit_msg%"=="" set commit_msg=Auto commit %date% %time%

echo Committing to %branch_name%...
git commit -m "%commit_msg%"
if errorlevel 1 (
    echo Nothing to commit.
    pause
    exit /b
)

:: Push to test branch
echo Pushing to origin/%branch_name%...
git push -u origin %branch_name%

if errorlevel 1 (
    echo.
    echo ========================================
    echo Push failed! Try manual commands:
    echo.
    echo git push -u origin test
    echo.
    echo Or if first push:
    echo git push -u origin HEAD:test
    echo ========================================
) else (
    echo.
    echo ========================================
    echo Success! Pushed to %branch_name% branch.
    echo ========================================
)

echo.
echo Done!
pause