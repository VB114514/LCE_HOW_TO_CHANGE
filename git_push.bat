@echo off
chcp 65001 >nul
title Git一键提交脚本

:: 设置项目路径（当前脚本所在目录，可手动修改）
set "project_path=%~dp0"
:: GitHub仓库URL
set "repo_url=https://github.com/VB114514/LCE_HOW_TO_CHANGE"

echo ========================================
echo        Git 一键提交脚本
echo ========================================
echo 项目路径：%project_path%
echo 远程仓库：%repo_url%
echo.

cd /d "%project_path%"

:: 检查是否已初始化Git仓库
if not exist ".git" (
    echo 未检测到Git仓库，正在初始化...
    git init
    git remote add origin %repo_url%
    echo.
)

:: 确保远程地址正确（防止重复添加）
git remote set-url origin %repo_url% 2>nul

:: 显示当前状态
echo 当前文件状态：
git status
echo.

:: 添加所有更改
echo 正在添加所有文件...
git add .
if errorlevel 1 (
    echo 添加文件失败！
    pause
    exit /b
)

:: 提交更改（支持自定义提交信息）
set /p commit_msg="请输入提交信息（直接回车使用默认）: "
if "%commit_msg%"=="" set commit_msg="Auto commit at %date% %time%"

echo 正在提交...
git commit -m %commit_msg%
if errorlevel 1 (
    echo 没有需要提交的更改或提交失败。
) else (
    echo 正在推送到远程仓库...
    git push -u origin test
    if errorlevel 1 (
        echo 推送失败，请检查网络或分支名称（尝试使用master分支）
        echo 尝试推送到master分支...
        git push -u origin master
    ) else (
        echo 提交成功！
    )
)

echo.
echo 操作完成！
pause