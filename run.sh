#!/bin/bash

echo "🚀 تشغيل النظام الذكي المتعدد المجالات"
echo "========================================"

# التأكد من وجود المجلد
mkdir -p build

echo "🔨 جاري البناء..."
cd build

# البناء
g++ -std=c++14 -o flexible_system ../main_system.cpp

if [ $? -eq 0 ]; then
    echo "✅ تم البناء بنجاح"
    echo "🎯 جاري التشغيل..."
    echo ""
    ./flexible_system
else
    echo "❌ فشل البناء"
    exit 1
fi
