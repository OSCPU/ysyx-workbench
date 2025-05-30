.section .data
.global video_payload, video_payload_end
.p2align 3
video_payload:
.incbin VIDEO_FILE
video_payload_end:

.global audio_payload, audio_payload_end
.p2align 3
audio_payload:
.incbin AUDIO_FILE
audio_payload_end:
