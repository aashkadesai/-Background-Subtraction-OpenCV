# 🎥 Background Subtraction with OpenCV  

## 📖 Overview  

This project demonstrates **background subtraction** using **OpenCV's BackgroundSubtractorMOG2** algorithm. The objective is to **detect moving objects** in a video by removing the background and replacing it with a **solid color**. This technique is widely used in **motion detection, object tracking, and real-time video analysis**.  

### 🔹 **Key Features:**  
✅ **Extract Background Model** – Generates a stable **background reference** from a video.  
✅ **Foreground Mask Creation** – Detects moving objects by applying **MOG2 background subtraction**.  
✅ **Replace Background with Solid Color** – Isolates objects while removing dynamic backgrounds.  
✅ **Frame-by-Frame Processing** – Processes video **in real time** using OpenCV.  

---

## 📂 Project Structure  

📁 Background-Subtraction-OpenCV
├── 📂 data/
│ ├── VIDEO_Walking.mp4
├── 📂 src/
│ ├── background_subtraction.cpp
├── 📂 results/
│ ├── background_model.jpg
│ ├── foreground_mask.jpg
│ ├── processed_video.avi
├── README.md


